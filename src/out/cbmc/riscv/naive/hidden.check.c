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
#include <stdio.h>
#include <stdlib.h>

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

struct StateT * slot_12(struct StateT * v202);
struct StateT * slot_143(struct StateT * v2298);
struct StateT * slot_120(struct StateT * v1930);
struct StateT * slot_167(struct StateT * v2682);
struct StateT * slot_152(struct StateT * v2442);
struct StateT * slot_199(struct StateT * v3194);
struct StateT * slot_92(struct StateT * v1482);
struct StateT * slot_31(struct StateT * v506);
struct StateT * slot_160(struct StateT * v2570);
struct StateT * slot_65(struct StateT * v1050);
struct StateT * slot_10(struct StateT * v170);
struct StateT * slot_150(struct StateT * v2410);
struct StateT * slot_74(struct StateT * v1194);
struct StateT * slot_107(struct StateT * v1722);
struct StateT * slot_136(struct StateT * v2186);
struct StateT * slot_84(struct StateT * v1354);
struct StateT * slot_28(struct StateT * v458);
struct StateT * slot_155(struct StateT * v2490);
struct StateT * slot_177(struct StateT * v2842);
struct StateT * slot_17(struct StateT * v282);
struct StateT * slot_181(struct StateT * v2906);
struct StateT * slot_197(struct StateT * v3162);
struct StateT * slot_207(struct StateT * v3322);
struct StateT * slot_156(struct StateT * v2506);
struct StateT * slot_154(struct StateT * v2474);
struct StateT * slot_68(struct StateT * v1098);
struct StateT * slot_105(struct StateT * v1690);
struct StateT * slot_27(struct StateT * v442);
struct StateT * slot_164(struct StateT * v2634);
struct StateT * slot_15(struct StateT * v250);
struct StateT * slot_133(struct StateT * v2138);
struct StateT * slot_56(struct StateT * v906);
struct StateT * slot_222(struct StateT * v3562);
struct StateT * slot_34(struct StateT * v554);
struct StateT * slot_171(struct StateT * v2746);
struct StateT * slot_162(struct StateT * v2602);
struct StateT * slot_21(struct StateT * v346);
struct StateT * slot_118(struct StateT * v1898);
struct StateT * slot_121(struct StateT * v1946);
struct StateT * slot_144(struct StateT * v2314);
struct StateT * slot_201(struct StateT * v3226);
struct StateT * slot_94(struct StateT * v1514);
struct StateT * slot_63(struct StateT * v1018);
struct StateT * slot_146(struct StateT * v2346);
struct StateT * slot_24(struct StateT * v394);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v3130);
struct StateT * slot_125(struct StateT * v2010);
struct StateT * slot_148(struct StateT * v2378);
struct StateT * slot_126(struct StateT * v2026);
struct StateT * slot_223(struct StateT * v3578);
struct StateT * slot_79(struct StateT * v1274);
struct StateT * slot_41(struct StateT * v666);
struct StateT * slot_39(struct StateT * v634);
struct StateT * slot_142(struct StateT * v2282);
struct StateT * slot_60(struct StateT * v970);
struct StateT * slot_112(struct StateT * v1802);
struct StateT * slot_47(struct StateT * v762);
struct StateT * slot_214(struct StateT * v3434);
struct StateT * slot_29(struct StateT * v474);
struct StateT * slot_16(struct StateT * v266);
struct StateT * slot_113(struct StateT * v1818);
struct StateT * slot_151(struct StateT * v2426);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_124(struct StateT * v1994);
struct StateT * slot_191(struct StateT * v3066);
struct StateT * slot_103(struct StateT * v1658);
struct StateT * slot_128(struct StateT * v2058);
struct StateT * slot_19(struct StateT * v314);
struct StateT * slot_87(struct StateT * v1402);
struct StateT * slot_67(struct StateT * v1082);
struct StateT * slot_81(struct StateT * v1306);
struct StateT * slot_95(struct StateT * v1530);
struct StateT * slot_115(struct StateT * v1850);
struct StateT * slot_78(struct StateT * v1258);
struct StateT * slot_32(struct StateT * v522);
struct StateT * slot_205(struct StateT * v3290);
struct StateT * slot_193(struct StateT * v3098);
struct StateT * slot_176(struct StateT * v2826);
struct StateT * slot_189(struct StateT * v3034);
struct StateT * slot_33(struct StateT * v538);
struct StateT * slot_35(struct StateT * v570);
struct StateT * slot_210(struct StateT * v3370);
struct StateT * slot_166(struct StateT * v2666);
struct StateT * slot_51(struct StateT * v826);
struct StateT * slot_52(struct StateT * v842);
struct StateT * slot_83(struct StateT * v1338);
struct StateT * slot_25(struct StateT * v410);
struct StateT * slot_209(struct StateT * v3354);
struct StateT * slot_3(struct StateT * v56);
struct StateT * slot_123(struct StateT * v1978);
struct StateT * slot_73(struct StateT * v1178);
struct StateT * slot_198(struct StateT * v3178);
struct StateT * slot_1(struct StateT * v23);
struct StateT * slot_187(struct StateT * v3002);
struct StateT * slot_97(struct StateT * v1562);
struct StateT * slot_182(struct StateT * v2922);
struct StateT * slot_38(struct StateT * v618);
struct StateT * slot_178(struct StateT * v2858);
struct StateT * slot_106(struct StateT * v1706);
struct StateT * slot_98(struct StateT * v1578);
struct StateT * slot_159(struct StateT * v2554);
struct StateT * slot_46(struct StateT * v746);
struct StateT * slot_212(struct StateT * v3402);
struct StateT * slot_132(struct StateT * v2122);
struct StateT * slot_130(struct StateT * v2090);
struct StateT * slot_211(struct StateT * v3386);
struct StateT * slot_20(struct StateT * v330);
struct StateT * slot_141(struct StateT * v2266);
struct StateT * slot_61(struct StateT * v986);
struct StateT * slot_30(struct StateT * v490);
struct StateT * slot_4(struct StateT * v72);
struct StateT * slot_18(struct StateT * v298);
struct StateT * slot_9(struct StateT * v154);
struct StateT * slot_183(struct StateT * v2938);
struct StateT * slot_43(struct StateT * v698);
struct StateT * slot_70(struct StateT * v1130);
struct StateT * slot_168(struct StateT * v2698);
struct StateT * slot_76(struct StateT * v1226);
struct StateT * slot_6(struct StateT * v106);
struct StateT * slot_225(struct StateT * v3610);
struct StateT * slot_55(struct StateT * v890);
struct StateT * slot_213(struct StateT * v3418);
struct StateT * slot_82(struct StateT * v1322);
struct StateT * slot_161(struct StateT * v2586);
struct StateT * slot_185(struct StateT * v2970);
struct StateT * slot_91(struct StateT * v1466);
struct StateT * slot_58(struct StateT * v938);
struct StateT * slot_89(struct StateT * v1434);
struct StateT * slot_66(struct StateT * v1066);
struct StateT * slot_140(struct StateT * v2250);
struct StateT * slot_49(struct StateT * v794);
struct StateT * slot_216(struct StateT * v3466);
struct StateT * slot_50(struct StateT * v810);
struct StateT * slot_37(struct StateT * v602);
struct StateT * slot_114(struct StateT * v1834);
struct StateT * slot_135(struct StateT * v2170);
struct StateT * slot_59(struct StateT * v954);
struct StateT * slot_192(struct StateT * v3082);
struct StateT * slot_40(struct StateT * v650);
struct StateT * slot_48(struct StateT * v778);
struct StateT * slot_77(struct StateT * v1242);
struct StateT * slot_85(struct StateT * v1370);
struct StateT * slot_75(struct StateT * v1210);
struct StateT * slot_72(struct StateT * v1162);
struct StateT * slot_119(struct StateT * v1914);
struct StateT * slot_71(struct StateT * v1146);
struct StateT * slot_101(struct StateT * v1626);
struct StateT * slot_108(struct StateT * v1738);
struct StateT * slot_116(struct StateT * v1866);
struct StateT * slot_93(struct StateT * v1498);
struct StateT * slot_88(struct StateT * v1418);
struct StateT * slot_96(struct StateT * v1546);
struct StateT * slot_215(struct StateT * v3450);
struct StateT * slot_45(struct StateT * v730);
struct StateT * slot_218(struct StateT * v3498);
struct StateT * slot_220(struct StateT * v3530);
struct StateT * slot_134(struct StateT * v2154);
struct StateT * slot_175(struct StateT * v2810);
struct StateT * slot_69(struct StateT * v1114);
struct StateT * slot_202(struct StateT * v3242);
struct StateT * slot_188(struct StateT * v3018);
struct StateT * slot_138(struct StateT * v2218);
struct StateT * slot_186(struct StateT * v2986);
struct StateT * slot_102(struct StateT * v1642);
struct StateT * slot_145(struct StateT * v2330);
struct StateT * slot_110(struct StateT * v1770);
struct StateT * slot_196(struct StateT * v3146);
struct StateT * slot_208(struct StateT * v3338);
struct StateT * slot_172(struct StateT * v2762);
struct StateT * slot_131(struct StateT * v2106);
struct StateT * slot_8(struct StateT * v138);
struct StateT * slot_180(struct StateT * v2890);
struct StateT * slot_203(struct StateT * v3258);
struct StateT * slot_190(struct StateT * v3050);
struct StateT * slot_157(struct StateT * v2522);
struct StateT * slot_200(struct StateT * v3210);
struct StateT * slot_173(struct StateT * v2778);
struct StateT * slot_149(struct StateT * v2394);
struct StateT * slot_5(struct StateT * v93);
struct StateT * slot_104(struct StateT * v1674);
struct StateT * slot_54(struct StateT * v874);
struct StateT * slot_26(struct StateT * v426);
struct StateT * slot_206(struct StateT * v3306);
struct StateT * slot_169(struct StateT * v2714);
struct StateT * slot_64(struct StateT * v1034);
struct StateT * slot_170(struct StateT * v2730);
struct StateT * slot_14(struct StateT * v234);
struct StateT * slot_53(struct StateT * v858);
struct StateT * slot_80(struct StateT * v1290);
struct StateT * slot_44(struct StateT * v714);
struct StateT * slot_137(struct StateT * v2202);
struct StateT * slot_122(struct StateT * v1962);
struct StateT * slot_99(struct StateT * v1594);
struct StateT * slot_179(struct StateT * v2874);
struct StateT * slot_219(struct StateT * v3514);
struct StateT * slot_36(struct StateT * v586);
struct StateT * slot_57(struct StateT * v922);
struct StateT * slot_62(struct StateT * v1002);
struct StateT * slot_22(struct StateT * v362);
struct StateT * slot_139(struct StateT * v2234);
struct StateT * slot_221(struct StateT * v3546);
struct StateT * slot_23(struct StateT * v378);
struct StateT * slot_153(struct StateT * v2458);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_86(struct StateT * v1386);
struct StateT * slot_129(struct StateT * v2074);
struct StateT * slot_158(struct StateT * v2538);
struct StateT * slot_100(struct StateT * v1610);
struct StateT * slot_127(struct StateT * v2042);
struct StateT * slot_217(struct StateT * v3482);
struct StateT * slot_13(struct StateT * v218);
struct StateT * slot_111(struct StateT * v1786);
struct StateT * slot_109(struct StateT * v1754);
struct StateT * slot_174(struct StateT * v2794);
struct StateT * slot_147(struct StateT * v2362);
struct StateT * slot_42(struct StateT * v682);
struct StateT * slot_224(struct StateT * v3594);
struct StateT * slot_163(struct StateT * v2618);
struct StateT * slot_184(struct StateT * v2954);
struct StateT * slot_204(struct StateT * v3274);
struct StateT * slot_194(struct StateT * v3114);
struct StateT * slot_165(struct StateT * v2650);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v1882);
struct StateT * slot_90(struct StateT * v1450);
struct StateT * slot_11(struct StateT * v186);
struct StateT * slot_12(struct StateT * v202) {
  int v203 = v202->timer;
  int v211 = v203 + 1;
  v202->timer = v211;
  int * v205 = v202->regs;
  int v206 = v205[8];
  int * v207 = v202->regs;
  int v215 = v206 + 1;
  v207[8] = v215;
  struct StateT * v209 = slot_13(v202);
  return v209;
}

struct StateT * slot_143(struct StateT * v2298) {
  int v2299 = v2298->timer;
  int v2307 = v2299 + 1;
  v2298->timer = v2307;
  int * v2301 = v2298->regs;
  int v2302 = v2301[8];
  int * v2303 = v2298->regs;
  int v2311 = v2302 + 1;
  v2303[8] = v2311;
  struct StateT * v2305 = slot_144(v2298);
  return v2305;
}

struct StateT * slot_120(struct StateT * v1930) {
  int v1931 = v1930->timer;
  int v1939 = v1931 + 1;
  v1930->timer = v1939;
  int * v1933 = v1930->regs;
  int v1934 = v1933[8];
  int * v1935 = v1930->regs;
  int v1943 = v1934 + 1;
  v1935[8] = v1943;
  struct StateT * v1937 = slot_121(v1930);
  return v1937;
}

struct StateT * slot_167(struct StateT * v2682) {
  int v2683 = v2682->timer;
  int v2691 = v2683 + 1;
  v2682->timer = v2691;
  int * v2685 = v2682->regs;
  int v2686 = v2685[8];
  int * v2687 = v2682->regs;
  int v2695 = v2686 + 1;
  v2687[8] = v2695;
  struct StateT * v2689 = slot_168(v2682);
  return v2689;
}

struct StateT * slot_152(struct StateT * v2442) {
  int v2443 = v2442->timer;
  int v2451 = v2443 + 1;
  v2442->timer = v2451;
  int * v2445 = v2442->regs;
  int v2446 = v2445[8];
  int * v2447 = v2442->regs;
  int v2455 = v2446 + 1;
  v2447[8] = v2455;
  struct StateT * v2449 = slot_153(v2442);
  return v2449;
}

struct StateT * slot_199(struct StateT * v3194) {
  int v3195 = v3194->timer;
  int v3203 = v3195 + 1;
  v3194->timer = v3203;
  int * v3197 = v3194->regs;
  int v3198 = v3197[8];
  int * v3199 = v3194->regs;
  int v3207 = v3198 + 1;
  v3199[8] = v3207;
  struct StateT * v3201 = slot_200(v3194);
  return v3201;
}

struct StateT * slot_92(struct StateT * v1482) {
  int v1483 = v1482->timer;
  int v1491 = v1483 + 1;
  v1482->timer = v1491;
  int * v1485 = v1482->regs;
  int v1486 = v1485[8];
  int * v1487 = v1482->regs;
  int v1495 = v1486 + 1;
  v1487[8] = v1495;
  struct StateT * v1489 = slot_93(v1482);
  return v1489;
}

struct StateT * slot_31(struct StateT * v506) {
  int v507 = v506->timer;
  int v515 = v507 + 1;
  v506->timer = v515;
  int * v509 = v506->regs;
  int v510 = v509[8];
  int * v511 = v506->regs;
  int v519 = v510 + 1;
  v511[8] = v519;
  struct StateT * v513 = slot_32(v506);
  return v513;
}

struct StateT * slot_160(struct StateT * v2570) {
  int v2571 = v2570->timer;
  int v2579 = v2571 + 1;
  v2570->timer = v2579;
  int * v2573 = v2570->regs;
  int v2574 = v2573[8];
  int * v2575 = v2570->regs;
  int v2583 = v2574 + 1;
  v2575[8] = v2583;
  struct StateT * v2577 = slot_161(v2570);
  return v2577;
}

struct StateT * slot_65(struct StateT * v1050) {
  int v1051 = v1050->timer;
  int v1059 = v1051 + 1;
  v1050->timer = v1059;
  int * v1053 = v1050->regs;
  int v1054 = v1053[8];
  int * v1055 = v1050->regs;
  int v1063 = v1054 + 1;
  v1055[8] = v1063;
  struct StateT * v1057 = slot_66(v1050);
  return v1057;
}

struct StateT * slot_10(struct StateT * v170) {
  int v171 = v170->timer;
  int v179 = v171 + 1;
  v170->timer = v179;
  int * v173 = v170->regs;
  int v174 = v173[8];
  int * v175 = v170->regs;
  int v183 = v174 + 1;
  v175[8] = v183;
  struct StateT * v177 = slot_11(v170);
  return v177;
}

struct StateT * slot_150(struct StateT * v2410) {
  int v2411 = v2410->timer;
  int v2419 = v2411 + 1;
  v2410->timer = v2419;
  int * v2413 = v2410->regs;
  int v2414 = v2413[8];
  int * v2415 = v2410->regs;
  int v2423 = v2414 + 1;
  v2415[8] = v2423;
  struct StateT * v2417 = slot_151(v2410);
  return v2417;
}

struct StateT * slot_74(struct StateT * v1194) {
  int v1195 = v1194->timer;
  int v1203 = v1195 + 1;
  v1194->timer = v1203;
  int * v1197 = v1194->regs;
  int v1198 = v1197[8];
  int * v1199 = v1194->regs;
  int v1207 = v1198 + 1;
  v1199[8] = v1207;
  struct StateT * v1201 = slot_75(v1194);
  return v1201;
}

struct StateT * slot_107(struct StateT * v1722) {
  int v1723 = v1722->timer;
  int v1731 = v1723 + 1;
  v1722->timer = v1731;
  int * v1725 = v1722->regs;
  int v1726 = v1725[8];
  int * v1727 = v1722->regs;
  int v1735 = v1726 + 1;
  v1727[8] = v1735;
  struct StateT * v1729 = slot_108(v1722);
  return v1729;
}

struct StateT * slot_136(struct StateT * v2186) {
  int v2187 = v2186->timer;
  int v2195 = v2187 + 1;
  v2186->timer = v2195;
  int * v2189 = v2186->regs;
  int v2190 = v2189[8];
  int * v2191 = v2186->regs;
  int v2199 = v2190 + 1;
  v2191[8] = v2199;
  struct StateT * v2193 = slot_137(v2186);
  return v2193;
}

struct StateT * slot_84(struct StateT * v1354) {
  int v1355 = v1354->timer;
  int v1363 = v1355 + 1;
  v1354->timer = v1363;
  int * v1357 = v1354->regs;
  int v1358 = v1357[8];
  int * v1359 = v1354->regs;
  int v1367 = v1358 + 1;
  v1359[8] = v1367;
  struct StateT * v1361 = slot_85(v1354);
  return v1361;
}

struct StateT * slot_28(struct StateT * v458) {
  int v459 = v458->timer;
  int v467 = v459 + 1;
  v458->timer = v467;
  int * v461 = v458->regs;
  int v462 = v461[8];
  int * v463 = v458->regs;
  int v471 = v462 + 1;
  v463[8] = v471;
  struct StateT * v465 = slot_29(v458);
  return v465;
}

struct StateT * slot_155(struct StateT * v2490) {
  int v2491 = v2490->timer;
  int v2499 = v2491 + 1;
  v2490->timer = v2499;
  int * v2493 = v2490->regs;
  int v2494 = v2493[8];
  int * v2495 = v2490->regs;
  int v2503 = v2494 + 1;
  v2495[8] = v2503;
  struct StateT * v2497 = slot_156(v2490);
  return v2497;
}

struct StateT * slot_177(struct StateT * v2842) {
  int v2843 = v2842->timer;
  int v2851 = v2843 + 1;
  v2842->timer = v2851;
  int * v2845 = v2842->regs;
  int v2846 = v2845[8];
  int * v2847 = v2842->regs;
  int v2855 = v2846 + 1;
  v2847[8] = v2855;
  struct StateT * v2849 = slot_178(v2842);
  return v2849;
}

struct StateT * slot_17(struct StateT * v282) {
  int v283 = v282->timer;
  int v291 = v283 + 1;
  v282->timer = v291;
  int * v285 = v282->regs;
  int v286 = v285[8];
  int * v287 = v282->regs;
  int v295 = v286 + 1;
  v287[8] = v295;
  struct StateT * v289 = slot_18(v282);
  return v289;
}

struct StateT * slot_181(struct StateT * v2906) {
  int v2907 = v2906->timer;
  int v2915 = v2907 + 1;
  v2906->timer = v2915;
  int * v2909 = v2906->regs;
  int v2910 = v2909[8];
  int * v2911 = v2906->regs;
  int v2919 = v2910 + 1;
  v2911[8] = v2919;
  struct StateT * v2913 = slot_182(v2906);
  return v2913;
}

struct StateT * slot_197(struct StateT * v3162) {
  int v3163 = v3162->timer;
  int v3171 = v3163 + 1;
  v3162->timer = v3171;
  int * v3165 = v3162->regs;
  int v3166 = v3165[8];
  int * v3167 = v3162->regs;
  int v3175 = v3166 + 1;
  v3167[8] = v3175;
  struct StateT * v3169 = slot_198(v3162);
  return v3169;
}

struct StateT * slot_207(struct StateT * v3322) {
  int v3323 = v3322->timer;
  int v3331 = v3323 + 1;
  v3322->timer = v3331;
  int * v3325 = v3322->regs;
  int v3326 = v3325[8];
  int * v3327 = v3322->regs;
  int v3335 = v3326 + 1;
  v3327[8] = v3335;
  struct StateT * v3329 = slot_208(v3322);
  return v3329;
}

struct StateT * slot_156(struct StateT * v2506) {
  int v2507 = v2506->timer;
  int v2515 = v2507 + 1;
  v2506->timer = v2515;
  int * v2509 = v2506->regs;
  int v2510 = v2509[8];
  int * v2511 = v2506->regs;
  int v2519 = v2510 + 1;
  v2511[8] = v2519;
  struct StateT * v2513 = slot_157(v2506);
  return v2513;
}

struct StateT * slot_154(struct StateT * v2474) {
  int v2475 = v2474->timer;
  int v2483 = v2475 + 1;
  v2474->timer = v2483;
  int * v2477 = v2474->regs;
  int v2478 = v2477[8];
  int * v2479 = v2474->regs;
  int v2487 = v2478 + 1;
  v2479[8] = v2487;
  struct StateT * v2481 = slot_155(v2474);
  return v2481;
}

struct StateT * slot_68(struct StateT * v1098) {
  int v1099 = v1098->timer;
  int v1107 = v1099 + 1;
  v1098->timer = v1107;
  int * v1101 = v1098->regs;
  int v1102 = v1101[8];
  int * v1103 = v1098->regs;
  int v1111 = v1102 + 1;
  v1103[8] = v1111;
  struct StateT * v1105 = slot_69(v1098);
  return v1105;
}

struct StateT * slot_105(struct StateT * v1690) {
  int v1691 = v1690->timer;
  int v1699 = v1691 + 1;
  v1690->timer = v1699;
  int * v1693 = v1690->regs;
  int v1694 = v1693[8];
  int * v1695 = v1690->regs;
  int v1703 = v1694 + 1;
  v1695[8] = v1703;
  struct StateT * v1697 = slot_106(v1690);
  return v1697;
}

struct StateT * slot_27(struct StateT * v442) {
  int v443 = v442->timer;
  int v451 = v443 + 1;
  v442->timer = v451;
  int * v445 = v442->regs;
  int v446 = v445[8];
  int * v447 = v442->regs;
  int v455 = v446 + 1;
  v447[8] = v455;
  struct StateT * v449 = slot_28(v442);
  return v449;
}

struct StateT * slot_164(struct StateT * v2634) {
  int v2635 = v2634->timer;
  int v2643 = v2635 + 1;
  v2634->timer = v2643;
  int * v2637 = v2634->regs;
  int v2638 = v2637[8];
  int * v2639 = v2634->regs;
  int v2647 = v2638 + 1;
  v2639[8] = v2647;
  struct StateT * v2641 = slot_165(v2634);
  return v2641;
}

struct StateT * slot_15(struct StateT * v250) {
  int v251 = v250->timer;
  int v259 = v251 + 1;
  v250->timer = v259;
  int * v253 = v250->regs;
  int v254 = v253[8];
  int * v255 = v250->regs;
  int v263 = v254 + 1;
  v255[8] = v263;
  struct StateT * v257 = slot_16(v250);
  return v257;
}

struct StateT * slot_133(struct StateT * v2138) {
  int v2139 = v2138->timer;
  int v2147 = v2139 + 1;
  v2138->timer = v2147;
  int * v2141 = v2138->regs;
  int v2142 = v2141[8];
  int * v2143 = v2138->regs;
  int v2151 = v2142 + 1;
  v2143[8] = v2151;
  struct StateT * v2145 = slot_134(v2138);
  return v2145;
}

struct StateT * slot_56(struct StateT * v906) {
  int v907 = v906->timer;
  int v915 = v907 + 1;
  v906->timer = v915;
  int * v909 = v906->regs;
  int v910 = v909[8];
  int * v911 = v906->regs;
  int v919 = v910 + 1;
  v911[8] = v919;
  struct StateT * v913 = slot_57(v906);
  return v913;
}

struct StateT * slot_222(struct StateT * v3562) {
  int v3563 = v3562->timer;
  int v3571 = v3563 + 1;
  v3562->timer = v3571;
  int * v3565 = v3562->regs;
  int v3566 = v3565[8];
  int * v3567 = v3562->regs;
  int v3575 = v3566 + 1;
  v3567[8] = v3575;
  struct StateT * v3569 = slot_223(v3562);
  return v3569;
}

struct StateT * slot_34(struct StateT * v554) {
  int v555 = v554->timer;
  int v563 = v555 + 1;
  v554->timer = v563;
  int * v557 = v554->regs;
  int v558 = v557[8];
  int * v559 = v554->regs;
  int v567 = v558 + 1;
  v559[8] = v567;
  struct StateT * v561 = slot_35(v554);
  return v561;
}

struct StateT * slot_171(struct StateT * v2746) {
  int v2747 = v2746->timer;
  int v2755 = v2747 + 1;
  v2746->timer = v2755;
  int * v2749 = v2746->regs;
  int v2750 = v2749[8];
  int * v2751 = v2746->regs;
  int v2759 = v2750 + 1;
  v2751[8] = v2759;
  struct StateT * v2753 = slot_172(v2746);
  return v2753;
}

struct StateT * slot_162(struct StateT * v2602) {
  int v2603 = v2602->timer;
  int v2611 = v2603 + 1;
  v2602->timer = v2611;
  int * v2605 = v2602->regs;
  int v2606 = v2605[8];
  int * v2607 = v2602->regs;
  int v2615 = v2606 + 1;
  v2607[8] = v2615;
  struct StateT * v2609 = slot_163(v2602);
  return v2609;
}

struct StateT * slot_21(struct StateT * v346) {
  int v347 = v346->timer;
  int v355 = v347 + 1;
  v346->timer = v355;
  int * v349 = v346->regs;
  int v350 = v349[8];
  int * v351 = v346->regs;
  int v359 = v350 + 1;
  v351[8] = v359;
  struct StateT * v353 = slot_22(v346);
  return v353;
}

struct StateT * slot_118(struct StateT * v1898) {
  int v1899 = v1898->timer;
  int v1907 = v1899 + 1;
  v1898->timer = v1907;
  int * v1901 = v1898->regs;
  int v1902 = v1901[8];
  int * v1903 = v1898->regs;
  int v1911 = v1902 + 1;
  v1903[8] = v1911;
  struct StateT * v1905 = slot_119(v1898);
  return v1905;
}

struct StateT * slot_121(struct StateT * v1946) {
  int v1947 = v1946->timer;
  int v1955 = v1947 + 1;
  v1946->timer = v1955;
  int * v1949 = v1946->regs;
  int v1950 = v1949[8];
  int * v1951 = v1946->regs;
  int v1959 = v1950 + 1;
  v1951[8] = v1959;
  struct StateT * v1953 = slot_122(v1946);
  return v1953;
}

struct StateT * slot_144(struct StateT * v2314) {
  int v2315 = v2314->timer;
  int v2323 = v2315 + 1;
  v2314->timer = v2323;
  int * v2317 = v2314->regs;
  int v2318 = v2317[8];
  int * v2319 = v2314->regs;
  int v2327 = v2318 + 1;
  v2319[8] = v2327;
  struct StateT * v2321 = slot_145(v2314);
  return v2321;
}

struct StateT * slot_201(struct StateT * v3226) {
  int v3227 = v3226->timer;
  int v3235 = v3227 + 1;
  v3226->timer = v3235;
  int * v3229 = v3226->regs;
  int v3230 = v3229[8];
  int * v3231 = v3226->regs;
  int v3239 = v3230 + 1;
  v3231[8] = v3239;
  struct StateT * v3233 = slot_202(v3226);
  return v3233;
}

struct StateT * slot_94(struct StateT * v1514) {
  int v1515 = v1514->timer;
  int v1523 = v1515 + 1;
  v1514->timer = v1523;
  int * v1517 = v1514->regs;
  int v1518 = v1517[8];
  int * v1519 = v1514->regs;
  int v1527 = v1518 + 1;
  v1519[8] = v1527;
  struct StateT * v1521 = slot_95(v1514);
  return v1521;
}

struct StateT * slot_63(struct StateT * v1018) {
  int v1019 = v1018->timer;
  int v1027 = v1019 + 1;
  v1018->timer = v1027;
  int * v1021 = v1018->regs;
  int v1022 = v1021[8];
  int * v1023 = v1018->regs;
  int v1031 = v1022 + 1;
  v1023[8] = v1031;
  struct StateT * v1025 = slot_64(v1018);
  return v1025;
}

struct StateT * slot_146(struct StateT * v2346) {
  int v2347 = v2346->timer;
  int v2355 = v2347 + 1;
  v2346->timer = v2355;
  int * v2349 = v2346->regs;
  int v2350 = v2349[8];
  int * v2351 = v2346->regs;
  int v2359 = v2350 + 1;
  v2351[8] = v2359;
  struct StateT * v2353 = slot_147(v2346);
  return v2353;
}

struct StateT * slot_24(struct StateT * v394) {
  int v395 = v394->timer;
  int v403 = v395 + 1;
  v394->timer = v403;
  int * v397 = v394->regs;
  int v398 = v397[8];
  int * v399 = v394->regs;
  int v407 = v398 + 1;
  v399[8] = v407;
  struct StateT * v401 = slot_25(v394);
  return v401;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v13 = v3 + 1;
  v2->timer = v13;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->mem;
  int v17 = (int)((unsigned int)v6 >> 2);
  int v8 = v7[v17];
  int * v9 = v2->regs;
  v9[5] = v8;
  struct StateT * v11 = slot_1(v2);
  return v11;
}

struct StateT * slot_195(struct StateT * v3130) {
  int v3131 = v3130->timer;
  int v3139 = v3131 + 1;
  v3130->timer = v3139;
  int * v3133 = v3130->regs;
  int v3134 = v3133[8];
  int * v3135 = v3130->regs;
  int v3143 = v3134 + 1;
  v3135[8] = v3143;
  struct StateT * v3137 = slot_196(v3130);
  return v3137;
}

struct StateT * slot_125(struct StateT * v2010) {
  int v2011 = v2010->timer;
  int v2019 = v2011 + 1;
  v2010->timer = v2019;
  int * v2013 = v2010->regs;
  int v2014 = v2013[8];
  int * v2015 = v2010->regs;
  int v2023 = v2014 + 1;
  v2015[8] = v2023;
  struct StateT * v2017 = slot_126(v2010);
  return v2017;
}

struct StateT * slot_148(struct StateT * v2378) {
  int v2379 = v2378->timer;
  int v2387 = v2379 + 1;
  v2378->timer = v2387;
  int * v2381 = v2378->regs;
  int v2382 = v2381[8];
  int * v2383 = v2378->regs;
  int v2391 = v2382 + 1;
  v2383[8] = v2391;
  struct StateT * v2385 = slot_149(v2378);
  return v2385;
}

struct StateT * slot_126(struct StateT * v2026) {
  int v2027 = v2026->timer;
  int v2035 = v2027 + 1;
  v2026->timer = v2035;
  int * v2029 = v2026->regs;
  int v2030 = v2029[8];
  int * v2031 = v2026->regs;
  int v2039 = v2030 + 1;
  v2031[8] = v2039;
  struct StateT * v2033 = slot_127(v2026);
  return v2033;
}

struct StateT * slot_223(struct StateT * v3578) {
  int v3579 = v3578->timer;
  int v3587 = v3579 + 1;
  v3578->timer = v3587;
  int * v3581 = v3578->regs;
  int v3582 = v3581[8];
  int * v3583 = v3578->regs;
  int v3591 = v3582 + 1;
  v3583[8] = v3591;
  struct StateT * v3585 = slot_224(v3578);
  return v3585;
}

struct StateT * slot_79(struct StateT * v1274) {
  int v1275 = v1274->timer;
  int v1283 = v1275 + 1;
  v1274->timer = v1283;
  int * v1277 = v1274->regs;
  int v1278 = v1277[8];
  int * v1279 = v1274->regs;
  int v1287 = v1278 + 1;
  v1279[8] = v1287;
  struct StateT * v1281 = slot_80(v1274);
  return v1281;
}

struct StateT * slot_41(struct StateT * v666) {
  int v667 = v666->timer;
  int v675 = v667 + 1;
  v666->timer = v675;
  int * v669 = v666->regs;
  int v670 = v669[8];
  int * v671 = v666->regs;
  int v679 = v670 + 1;
  v671[8] = v679;
  struct StateT * v673 = slot_42(v666);
  return v673;
}

struct StateT * slot_39(struct StateT * v634) {
  int v635 = v634->timer;
  int v643 = v635 + 1;
  v634->timer = v643;
  int * v637 = v634->regs;
  int v638 = v637[8];
  int * v639 = v634->regs;
  int v647 = v638 + 1;
  v639[8] = v647;
  struct StateT * v641 = slot_40(v634);
  return v641;
}

struct StateT * slot_142(struct StateT * v2282) {
  int v2283 = v2282->timer;
  int v2291 = v2283 + 1;
  v2282->timer = v2291;
  int * v2285 = v2282->regs;
  int v2286 = v2285[8];
  int * v2287 = v2282->regs;
  int v2295 = v2286 + 1;
  v2287[8] = v2295;
  struct StateT * v2289 = slot_143(v2282);
  return v2289;
}

struct StateT * slot_60(struct StateT * v970) {
  int v971 = v970->timer;
  int v979 = v971 + 1;
  v970->timer = v979;
  int * v973 = v970->regs;
  int v974 = v973[8];
  int * v975 = v970->regs;
  int v983 = v974 + 1;
  v975[8] = v983;
  struct StateT * v977 = slot_61(v970);
  return v977;
}

struct StateT * slot_112(struct StateT * v1802) {
  int v1803 = v1802->timer;
  int v1811 = v1803 + 1;
  v1802->timer = v1811;
  int * v1805 = v1802->regs;
  int v1806 = v1805[8];
  int * v1807 = v1802->regs;
  int v1815 = v1806 + 1;
  v1807[8] = v1815;
  struct StateT * v1809 = slot_113(v1802);
  return v1809;
}

struct StateT * slot_47(struct StateT * v762) {
  int v763 = v762->timer;
  int v771 = v763 + 1;
  v762->timer = v771;
  int * v765 = v762->regs;
  int v766 = v765[8];
  int * v767 = v762->regs;
  int v775 = v766 + 1;
  v767[8] = v775;
  struct StateT * v769 = slot_48(v762);
  return v769;
}

struct StateT * slot_214(struct StateT * v3434) {
  int v3435 = v3434->timer;
  int v3443 = v3435 + 1;
  v3434->timer = v3443;
  int * v3437 = v3434->regs;
  int v3438 = v3437[8];
  int * v3439 = v3434->regs;
  int v3447 = v3438 + 1;
  v3439[8] = v3447;
  struct StateT * v3441 = slot_215(v3434);
  return v3441;
}

struct StateT * slot_29(struct StateT * v474) {
  int v475 = v474->timer;
  int v483 = v475 + 1;
  v474->timer = v483;
  int * v477 = v474->regs;
  int v478 = v477[8];
  int * v479 = v474->regs;
  int v487 = v478 + 1;
  v479[8] = v487;
  struct StateT * v481 = slot_30(v474);
  return v481;
}

struct StateT * slot_16(struct StateT * v266) {
  int v267 = v266->timer;
  int v275 = v267 + 1;
  v266->timer = v275;
  int * v269 = v266->regs;
  int v270 = v269[8];
  int * v271 = v266->regs;
  int v279 = v270 + 1;
  v271[8] = v279;
  struct StateT * v273 = slot_17(v266);
  return v273;
}

struct StateT * slot_113(struct StateT * v1818) {
  int v1819 = v1818->timer;
  int v1827 = v1819 + 1;
  v1818->timer = v1827;
  int * v1821 = v1818->regs;
  int v1822 = v1821[8];
  int * v1823 = v1818->regs;
  int v1831 = v1822 + 1;
  v1823[8] = v1831;
  struct StateT * v1825 = slot_114(v1818);
  return v1825;
}

struct StateT * slot_151(struct StateT * v2426) {
  int v2427 = v2426->timer;
  int v2435 = v2427 + 1;
  v2426->timer = v2435;
  int * v2429 = v2426->regs;
  int v2430 = v2429[8];
  int * v2431 = v2426->regs;
  int v2439 = v2430 + 1;
  v2431[8] = v2439;
  struct StateT * v2433 = slot_152(v2426);
  return v2433;
}

struct StateT * slot_7(struct StateT * v122) {
  int v123 = v122->timer;
  int v131 = v123 + 1;
  v122->timer = v131;
  int * v125 = v122->regs;
  int v126 = v125[8];
  int * v127 = v122->regs;
  int v135 = v126 + 1;
  v127[8] = v135;
  struct StateT * v129 = slot_8(v122);
  return v129;
}

struct StateT * slot_124(struct StateT * v1994) {
  int v1995 = v1994->timer;
  int v2003 = v1995 + 1;
  v1994->timer = v2003;
  int * v1997 = v1994->regs;
  int v1998 = v1997[8];
  int * v1999 = v1994->regs;
  int v2007 = v1998 + 1;
  v1999[8] = v2007;
  struct StateT * v2001 = slot_125(v1994);
  return v2001;
}

struct StateT * slot_191(struct StateT * v3066) {
  int v3067 = v3066->timer;
  int v3075 = v3067 + 1;
  v3066->timer = v3075;
  int * v3069 = v3066->regs;
  int v3070 = v3069[8];
  int * v3071 = v3066->regs;
  int v3079 = v3070 + 1;
  v3071[8] = v3079;
  struct StateT * v3073 = slot_192(v3066);
  return v3073;
}

struct StateT * slot_103(struct StateT * v1658) {
  int v1659 = v1658->timer;
  int v1667 = v1659 + 1;
  v1658->timer = v1667;
  int * v1661 = v1658->regs;
  int v1662 = v1661[8];
  int * v1663 = v1658->regs;
  int v1671 = v1662 + 1;
  v1663[8] = v1671;
  struct StateT * v1665 = slot_104(v1658);
  return v1665;
}

struct StateT * slot_128(struct StateT * v2058) {
  int v2059 = v2058->timer;
  int v2067 = v2059 + 1;
  v2058->timer = v2067;
  int * v2061 = v2058->regs;
  int v2062 = v2061[8];
  int * v2063 = v2058->regs;
  int v2071 = v2062 + 1;
  v2063[8] = v2071;
  struct StateT * v2065 = slot_129(v2058);
  return v2065;
}

struct StateT * slot_19(struct StateT * v314) {
  int v315 = v314->timer;
  int v323 = v315 + 1;
  v314->timer = v323;
  int * v317 = v314->regs;
  int v318 = v317[8];
  int * v319 = v314->regs;
  int v327 = v318 + 1;
  v319[8] = v327;
  struct StateT * v321 = slot_20(v314);
  return v321;
}

struct StateT * slot_87(struct StateT * v1402) {
  int v1403 = v1402->timer;
  int v1411 = v1403 + 1;
  v1402->timer = v1411;
  int * v1405 = v1402->regs;
  int v1406 = v1405[8];
  int * v1407 = v1402->regs;
  int v1415 = v1406 + 1;
  v1407[8] = v1415;
  struct StateT * v1409 = slot_88(v1402);
  return v1409;
}

struct StateT * slot_67(struct StateT * v1082) {
  int v1083 = v1082->timer;
  int v1091 = v1083 + 1;
  v1082->timer = v1091;
  int * v1085 = v1082->regs;
  int v1086 = v1085[8];
  int * v1087 = v1082->regs;
  int v1095 = v1086 + 1;
  v1087[8] = v1095;
  struct StateT * v1089 = slot_68(v1082);
  return v1089;
}

struct StateT * slot_81(struct StateT * v1306) {
  int v1307 = v1306->timer;
  int v1315 = v1307 + 1;
  v1306->timer = v1315;
  int * v1309 = v1306->regs;
  int v1310 = v1309[8];
  int * v1311 = v1306->regs;
  int v1319 = v1310 + 1;
  v1311[8] = v1319;
  struct StateT * v1313 = slot_82(v1306);
  return v1313;
}

struct StateT * slot_95(struct StateT * v1530) {
  int v1531 = v1530->timer;
  int v1539 = v1531 + 1;
  v1530->timer = v1539;
  int * v1533 = v1530->regs;
  int v1534 = v1533[8];
  int * v1535 = v1530->regs;
  int v1543 = v1534 + 1;
  v1535[8] = v1543;
  struct StateT * v1537 = slot_96(v1530);
  return v1537;
}

struct StateT * slot_115(struct StateT * v1850) {
  int v1851 = v1850->timer;
  int v1859 = v1851 + 1;
  v1850->timer = v1859;
  int * v1853 = v1850->regs;
  int v1854 = v1853[8];
  int * v1855 = v1850->regs;
  int v1863 = v1854 + 1;
  v1855[8] = v1863;
  struct StateT * v1857 = slot_116(v1850);
  return v1857;
}

struct StateT * slot_78(struct StateT * v1258) {
  int v1259 = v1258->timer;
  int v1267 = v1259 + 1;
  v1258->timer = v1267;
  int * v1261 = v1258->regs;
  int v1262 = v1261[8];
  int * v1263 = v1258->regs;
  int v1271 = v1262 + 1;
  v1263[8] = v1271;
  struct StateT * v1265 = slot_79(v1258);
  return v1265;
}

struct StateT * slot_32(struct StateT * v522) {
  int v523 = v522->timer;
  int v531 = v523 + 1;
  v522->timer = v531;
  int * v525 = v522->regs;
  int v526 = v525[8];
  int * v527 = v522->regs;
  int v535 = v526 + 1;
  v527[8] = v535;
  struct StateT * v529 = slot_33(v522);
  return v529;
}

struct StateT * slot_205(struct StateT * v3290) {
  int v3291 = v3290->timer;
  int v3299 = v3291 + 1;
  v3290->timer = v3299;
  int * v3293 = v3290->regs;
  int v3294 = v3293[8];
  int * v3295 = v3290->regs;
  int v3303 = v3294 + 1;
  v3295[8] = v3303;
  struct StateT * v3297 = slot_206(v3290);
  return v3297;
}

struct StateT * slot_193(struct StateT * v3098) {
  int v3099 = v3098->timer;
  int v3107 = v3099 + 1;
  v3098->timer = v3107;
  int * v3101 = v3098->regs;
  int v3102 = v3101[8];
  int * v3103 = v3098->regs;
  int v3111 = v3102 + 1;
  v3103[8] = v3111;
  struct StateT * v3105 = slot_194(v3098);
  return v3105;
}

struct StateT * slot_176(struct StateT * v2826) {
  int v2827 = v2826->timer;
  int v2835 = v2827 + 1;
  v2826->timer = v2835;
  int * v2829 = v2826->regs;
  int v2830 = v2829[8];
  int * v2831 = v2826->regs;
  int v2839 = v2830 + 1;
  v2831[8] = v2839;
  struct StateT * v2833 = slot_177(v2826);
  return v2833;
}

struct StateT * slot_189(struct StateT * v3034) {
  int v3035 = v3034->timer;
  int v3043 = v3035 + 1;
  v3034->timer = v3043;
  int * v3037 = v3034->regs;
  int v3038 = v3037[8];
  int * v3039 = v3034->regs;
  int v3047 = v3038 + 1;
  v3039[8] = v3047;
  struct StateT * v3041 = slot_190(v3034);
  return v3041;
}

struct StateT * slot_33(struct StateT * v538) {
  int v539 = v538->timer;
  int v547 = v539 + 1;
  v538->timer = v547;
  int * v541 = v538->regs;
  int v542 = v541[8];
  int * v543 = v538->regs;
  int v551 = v542 + 1;
  v543[8] = v551;
  struct StateT * v545 = slot_34(v538);
  return v545;
}

struct StateT * slot_35(struct StateT * v570) {
  int v571 = v570->timer;
  int v579 = v571 + 1;
  v570->timer = v579;
  int * v573 = v570->regs;
  int v574 = v573[8];
  int * v575 = v570->regs;
  int v583 = v574 + 1;
  v575[8] = v583;
  struct StateT * v577 = slot_36(v570);
  return v577;
}

struct StateT * slot_210(struct StateT * v3370) {
  int v3371 = v3370->timer;
  int v3379 = v3371 + 1;
  v3370->timer = v3379;
  int * v3373 = v3370->regs;
  int v3374 = v3373[8];
  int * v3375 = v3370->regs;
  int v3383 = v3374 + 1;
  v3375[8] = v3383;
  struct StateT * v3377 = slot_211(v3370);
  return v3377;
}

struct StateT * slot_166(struct StateT * v2666) {
  int v2667 = v2666->timer;
  int v2675 = v2667 + 1;
  v2666->timer = v2675;
  int * v2669 = v2666->regs;
  int v2670 = v2669[8];
  int * v2671 = v2666->regs;
  int v2679 = v2670 + 1;
  v2671[8] = v2679;
  struct StateT * v2673 = slot_167(v2666);
  return v2673;
}

struct StateT * slot_51(struct StateT * v826) {
  int v827 = v826->timer;
  int v835 = v827 + 1;
  v826->timer = v835;
  int * v829 = v826->regs;
  int v830 = v829[8];
  int * v831 = v826->regs;
  int v839 = v830 + 1;
  v831[8] = v839;
  struct StateT * v833 = slot_52(v826);
  return v833;
}

struct StateT * slot_52(struct StateT * v842) {
  int v843 = v842->timer;
  int v851 = v843 + 1;
  v842->timer = v851;
  int * v845 = v842->regs;
  int v846 = v845[8];
  int * v847 = v842->regs;
  int v855 = v846 + 1;
  v847[8] = v855;
  struct StateT * v849 = slot_53(v842);
  return v849;
}

struct StateT * slot_83(struct StateT * v1338) {
  int v1339 = v1338->timer;
  int v1347 = v1339 + 1;
  v1338->timer = v1347;
  int * v1341 = v1338->regs;
  int v1342 = v1341[8];
  int * v1343 = v1338->regs;
  int v1351 = v1342 + 1;
  v1343[8] = v1351;
  struct StateT * v1345 = slot_84(v1338);
  return v1345;
}

struct StateT * slot_25(struct StateT * v410) {
  int v411 = v410->timer;
  int v419 = v411 + 1;
  v410->timer = v419;
  int * v413 = v410->regs;
  int v414 = v413[8];
  int * v415 = v410->regs;
  int v423 = v414 + 1;
  v415[8] = v423;
  struct StateT * v417 = slot_26(v410);
  return v417;
}

struct StateT * slot_209(struct StateT * v3354) {
  int v3355 = v3354->timer;
  int v3363 = v3355 + 1;
  v3354->timer = v3363;
  int * v3357 = v3354->regs;
  int v3358 = v3357[8];
  int * v3359 = v3354->regs;
  int v3367 = v3358 + 1;
  v3359[8] = v3367;
  struct StateT * v3361 = slot_210(v3354);
  return v3361;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v65 = v57 + 1;
  v56->timer = v65;
  int * v59 = v56->regs;
  int v60 = v59[6];
  int * v61 = v56->regs;
  int v69 = v60 << 2;
  v61[6] = v69;
  struct StateT * v63 = slot_4(v56);
  return v63;
}

struct StateT * slot_123(struct StateT * v1978) {
  int v1979 = v1978->timer;
  int v1987 = v1979 + 1;
  v1978->timer = v1987;
  int * v1981 = v1978->regs;
  int v1982 = v1981[8];
  int * v1983 = v1978->regs;
  int v1991 = v1982 + 1;
  v1983[8] = v1991;
  struct StateT * v1985 = slot_124(v1978);
  return v1985;
}

struct StateT * slot_73(struct StateT * v1178) {
  int v1179 = v1178->timer;
  int v1187 = v1179 + 1;
  v1178->timer = v1187;
  int * v1181 = v1178->regs;
  int v1182 = v1181[8];
  int * v1183 = v1178->regs;
  int v1191 = v1182 + 1;
  v1183[8] = v1191;
  struct StateT * v1185 = slot_74(v1178);
  return v1185;
}

struct StateT * slot_198(struct StateT * v3178) {
  int v3179 = v3178->timer;
  int v3187 = v3179 + 1;
  v3178->timer = v3187;
  int * v3181 = v3178->regs;
  int v3182 = v3181[8];
  int * v3183 = v3178->regs;
  int v3191 = v3182 + 1;
  v3183[8] = v3191;
  struct StateT * v3185 = slot_199(v3178);
  return v3185;
}

struct StateT * slot_1(struct StateT * v23) {
  int v24 = v23->timer;
  int v32 = v24 + 1;
  v23->timer = v32;
  int * v26 = v23->mem;
  int v27 = v26[20];
  int * v28 = v23->regs;
  v28[6] = v27;
  struct StateT * v30 = slot_2(v23);
  return v30;
}

struct StateT * slot_187(struct StateT * v3002) {
  int v3003 = v3002->timer;
  int v3011 = v3003 + 1;
  v3002->timer = v3011;
  int * v3005 = v3002->regs;
  int v3006 = v3005[8];
  int * v3007 = v3002->regs;
  int v3015 = v3006 + 1;
  v3007[8] = v3015;
  struct StateT * v3009 = slot_188(v3002);
  return v3009;
}

struct StateT * slot_97(struct StateT * v1562) {
  int v1563 = v1562->timer;
  int v1571 = v1563 + 1;
  v1562->timer = v1571;
  int * v1565 = v1562->regs;
  int v1566 = v1565[8];
  int * v1567 = v1562->regs;
  int v1575 = v1566 + 1;
  v1567[8] = v1575;
  struct StateT * v1569 = slot_98(v1562);
  return v1569;
}

struct StateT * slot_182(struct StateT * v2922) {
  int v2923 = v2922->timer;
  int v2931 = v2923 + 1;
  v2922->timer = v2931;
  int * v2925 = v2922->regs;
  int v2926 = v2925[8];
  int * v2927 = v2922->regs;
  int v2935 = v2926 + 1;
  v2927[8] = v2935;
  struct StateT * v2929 = slot_183(v2922);
  return v2929;
}

struct StateT * slot_38(struct StateT * v618) {
  int v619 = v618->timer;
  int v627 = v619 + 1;
  v618->timer = v627;
  int * v621 = v618->regs;
  int v622 = v621[8];
  int * v623 = v618->regs;
  int v631 = v622 + 1;
  v623[8] = v631;
  struct StateT * v625 = slot_39(v618);
  return v625;
}

struct StateT * slot_178(struct StateT * v2858) {
  int v2859 = v2858->timer;
  int v2867 = v2859 + 1;
  v2858->timer = v2867;
  int * v2861 = v2858->regs;
  int v2862 = v2861[8];
  int * v2863 = v2858->regs;
  int v2871 = v2862 + 1;
  v2863[8] = v2871;
  struct StateT * v2865 = slot_179(v2858);
  return v2865;
}

struct StateT * slot_106(struct StateT * v1706) {
  int v1707 = v1706->timer;
  int v1715 = v1707 + 1;
  v1706->timer = v1715;
  int * v1709 = v1706->regs;
  int v1710 = v1709[8];
  int * v1711 = v1706->regs;
  int v1719 = v1710 + 1;
  v1711[8] = v1719;
  struct StateT * v1713 = slot_107(v1706);
  return v1713;
}

struct StateT * slot_98(struct StateT * v1578) {
  int v1579 = v1578->timer;
  int v1587 = v1579 + 1;
  v1578->timer = v1587;
  int * v1581 = v1578->regs;
  int v1582 = v1581[8];
  int * v1583 = v1578->regs;
  int v1591 = v1582 + 1;
  v1583[8] = v1591;
  struct StateT * v1585 = slot_99(v1578);
  return v1585;
}

struct StateT * slot_159(struct StateT * v2554) {
  int v2555 = v2554->timer;
  int v2563 = v2555 + 1;
  v2554->timer = v2563;
  int * v2557 = v2554->regs;
  int v2558 = v2557[8];
  int * v2559 = v2554->regs;
  int v2567 = v2558 + 1;
  v2559[8] = v2567;
  struct StateT * v2561 = slot_160(v2554);
  return v2561;
}

struct StateT * slot_46(struct StateT * v746) {
  int v747 = v746->timer;
  int v755 = v747 + 1;
  v746->timer = v755;
  int * v749 = v746->regs;
  int v750 = v749[8];
  int * v751 = v746->regs;
  int v759 = v750 + 1;
  v751[8] = v759;
  struct StateT * v753 = slot_47(v746);
  return v753;
}

struct StateT * slot_212(struct StateT * v3402) {
  int v3403 = v3402->timer;
  int v3411 = v3403 + 1;
  v3402->timer = v3411;
  int * v3405 = v3402->regs;
  int v3406 = v3405[8];
  int * v3407 = v3402->regs;
  int v3415 = v3406 + 1;
  v3407[8] = v3415;
  struct StateT * v3409 = slot_213(v3402);
  return v3409;
}

struct StateT * slot_132(struct StateT * v2122) {
  int v2123 = v2122->timer;
  int v2131 = v2123 + 1;
  v2122->timer = v2131;
  int * v2125 = v2122->regs;
  int v2126 = v2125[8];
  int * v2127 = v2122->regs;
  int v2135 = v2126 + 1;
  v2127[8] = v2135;
  struct StateT * v2129 = slot_133(v2122);
  return v2129;
}

struct StateT * slot_130(struct StateT * v2090) {
  int v2091 = v2090->timer;
  int v2099 = v2091 + 1;
  v2090->timer = v2099;
  int * v2093 = v2090->regs;
  int v2094 = v2093[8];
  int * v2095 = v2090->regs;
  int v2103 = v2094 + 1;
  v2095[8] = v2103;
  struct StateT * v2097 = slot_131(v2090);
  return v2097;
}

struct StateT * slot_211(struct StateT * v3386) {
  int v3387 = v3386->timer;
  int v3395 = v3387 + 1;
  v3386->timer = v3395;
  int * v3389 = v3386->regs;
  int v3390 = v3389[8];
  int * v3391 = v3386->regs;
  int v3399 = v3390 + 1;
  v3391[8] = v3399;
  struct StateT * v3393 = slot_212(v3386);
  return v3393;
}

struct StateT * slot_20(struct StateT * v330) {
  int v331 = v330->timer;
  int v339 = v331 + 1;
  v330->timer = v339;
  int * v333 = v330->regs;
  int v334 = v333[8];
  int * v335 = v330->regs;
  int v343 = v334 + 1;
  v335[8] = v343;
  struct StateT * v337 = slot_21(v330);
  return v337;
}

struct StateT * slot_141(struct StateT * v2266) {
  int v2267 = v2266->timer;
  int v2275 = v2267 + 1;
  v2266->timer = v2275;
  int * v2269 = v2266->regs;
  int v2270 = v2269[8];
  int * v2271 = v2266->regs;
  int v2279 = v2270 + 1;
  v2271[8] = v2279;
  struct StateT * v2273 = slot_142(v2266);
  return v2273;
}

struct StateT * slot_61(struct StateT * v986) {
  int v987 = v986->timer;
  int v995 = v987 + 1;
  v986->timer = v995;
  int * v989 = v986->regs;
  int v990 = v989[8];
  int * v991 = v986->regs;
  int v999 = v990 + 1;
  v991[8] = v999;
  struct StateT * v993 = slot_62(v986);
  return v993;
}

struct StateT * slot_30(struct StateT * v490) {
  int v491 = v490->timer;
  int v499 = v491 + 1;
  v490->timer = v499;
  int * v493 = v490->regs;
  int v494 = v493[8];
  int * v495 = v490->regs;
  int v503 = v494 + 1;
  v495[8] = v503;
  struct StateT * v497 = slot_31(v490);
  return v497;
}

struct StateT * slot_4(struct StateT * v72) {
  int v73 = v72->timer;
  int v83 = v73 + 1;
  v72->timer = v83;
  int * v75 = v72->regs;
  int v76 = v75[6];
  int * v77 = v72->mem;
  int v87 = (int)((unsigned int)v76 >> 2);
  int v78 = v77[v87];
  int * v79 = v72->regs;
  v79[7] = v78;
  struct StateT * v81 = slot_5(v72);
  return v81;
}

struct StateT * slot_18(struct StateT * v298) {
  int v299 = v298->timer;
  int v307 = v299 + 1;
  v298->timer = v307;
  int * v301 = v298->regs;
  int v302 = v301[8];
  int * v303 = v298->regs;
  int v311 = v302 + 1;
  v303[8] = v311;
  struct StateT * v305 = slot_19(v298);
  return v305;
}

struct StateT * slot_9(struct StateT * v154) {
  int v155 = v154->timer;
  int v163 = v155 + 1;
  v154->timer = v163;
  int * v157 = v154->regs;
  int v158 = v157[8];
  int * v159 = v154->regs;
  int v167 = v158 + 1;
  v159[8] = v167;
  struct StateT * v161 = slot_10(v154);
  return v161;
}

struct StateT * slot_183(struct StateT * v2938) {
  int v2939 = v2938->timer;
  int v2947 = v2939 + 1;
  v2938->timer = v2947;
  int * v2941 = v2938->regs;
  int v2942 = v2941[8];
  int * v2943 = v2938->regs;
  int v2951 = v2942 + 1;
  v2943[8] = v2951;
  struct StateT * v2945 = slot_184(v2938);
  return v2945;
}

struct StateT * slot_43(struct StateT * v698) {
  int v699 = v698->timer;
  int v707 = v699 + 1;
  v698->timer = v707;
  int * v701 = v698->regs;
  int v702 = v701[8];
  int * v703 = v698->regs;
  int v711 = v702 + 1;
  v703[8] = v711;
  struct StateT * v705 = slot_44(v698);
  return v705;
}

struct StateT * slot_70(struct StateT * v1130) {
  int v1131 = v1130->timer;
  int v1139 = v1131 + 1;
  v1130->timer = v1139;
  int * v1133 = v1130->regs;
  int v1134 = v1133[8];
  int * v1135 = v1130->regs;
  int v1143 = v1134 + 1;
  v1135[8] = v1143;
  struct StateT * v1137 = slot_71(v1130);
  return v1137;
}

struct StateT * slot_168(struct StateT * v2698) {
  int v2699 = v2698->timer;
  int v2707 = v2699 + 1;
  v2698->timer = v2707;
  int * v2701 = v2698->regs;
  int v2702 = v2701[8];
  int * v2703 = v2698->regs;
  int v2711 = v2702 + 1;
  v2703[8] = v2711;
  struct StateT * v2705 = slot_169(v2698);
  return v2705;
}

struct StateT * slot_76(struct StateT * v1226) {
  int v1227 = v1226->timer;
  int v1235 = v1227 + 1;
  v1226->timer = v1235;
  int * v1229 = v1226->regs;
  int v1230 = v1229[8];
  int * v1231 = v1226->regs;
  int v1239 = v1230 + 1;
  v1231[8] = v1239;
  struct StateT * v1233 = slot_77(v1226);
  return v1233;
}

struct StateT * slot_6(struct StateT * v106) {
  int v107 = v106->timer;
  int v115 = v107 + 1;
  v106->timer = v115;
  int * v109 = v106->regs;
  int v110 = v109[8];
  int * v111 = v106->regs;
  int v119 = v110 + 1;
  v111[8] = v119;
  struct StateT * v113 = slot_7(v106);
  return v113;
}

struct StateT * slot_225(struct StateT * v3610) {
  int v3611 = v3610->timer;
  int v3618 = v3611 + 1;
  v3610->timer = v3618;
  int * v3613 = v3610->regs;
  int v3614 = v3613[8];
  int * v3615 = v3610->regs;
  int v3622 = v3614 + 1;
  v3615[8] = v3622;
  return v3610;
}

struct StateT * slot_55(struct StateT * v890) {
  int v891 = v890->timer;
  int v899 = v891 + 1;
  v890->timer = v899;
  int * v893 = v890->regs;
  int v894 = v893[8];
  int * v895 = v890->regs;
  int v903 = v894 + 1;
  v895[8] = v903;
  struct StateT * v897 = slot_56(v890);
  return v897;
}

struct StateT * slot_213(struct StateT * v3418) {
  int v3419 = v3418->timer;
  int v3427 = v3419 + 1;
  v3418->timer = v3427;
  int * v3421 = v3418->regs;
  int v3422 = v3421[8];
  int * v3423 = v3418->regs;
  int v3431 = v3422 + 1;
  v3423[8] = v3431;
  struct StateT * v3425 = slot_214(v3418);
  return v3425;
}

struct StateT * slot_82(struct StateT * v1322) {
  int v1323 = v1322->timer;
  int v1331 = v1323 + 1;
  v1322->timer = v1331;
  int * v1325 = v1322->regs;
  int v1326 = v1325[8];
  int * v1327 = v1322->regs;
  int v1335 = v1326 + 1;
  v1327[8] = v1335;
  struct StateT * v1329 = slot_83(v1322);
  return v1329;
}

struct StateT * slot_161(struct StateT * v2586) {
  int v2587 = v2586->timer;
  int v2595 = v2587 + 1;
  v2586->timer = v2595;
  int * v2589 = v2586->regs;
  int v2590 = v2589[8];
  int * v2591 = v2586->regs;
  int v2599 = v2590 + 1;
  v2591[8] = v2599;
  struct StateT * v2593 = slot_162(v2586);
  return v2593;
}

struct StateT * slot_185(struct StateT * v2970) {
  int v2971 = v2970->timer;
  int v2979 = v2971 + 1;
  v2970->timer = v2979;
  int * v2973 = v2970->regs;
  int v2974 = v2973[8];
  int * v2975 = v2970->regs;
  int v2983 = v2974 + 1;
  v2975[8] = v2983;
  struct StateT * v2977 = slot_186(v2970);
  return v2977;
}

struct StateT * slot_91(struct StateT * v1466) {
  int v1467 = v1466->timer;
  int v1475 = v1467 + 1;
  v1466->timer = v1475;
  int * v1469 = v1466->regs;
  int v1470 = v1469[8];
  int * v1471 = v1466->regs;
  int v1479 = v1470 + 1;
  v1471[8] = v1479;
  struct StateT * v1473 = slot_92(v1466);
  return v1473;
}

struct StateT * slot_58(struct StateT * v938) {
  int v939 = v938->timer;
  int v947 = v939 + 1;
  v938->timer = v947;
  int * v941 = v938->regs;
  int v942 = v941[8];
  int * v943 = v938->regs;
  int v951 = v942 + 1;
  v943[8] = v951;
  struct StateT * v945 = slot_59(v938);
  return v945;
}

struct StateT * slot_89(struct StateT * v1434) {
  int v1435 = v1434->timer;
  int v1443 = v1435 + 1;
  v1434->timer = v1443;
  int * v1437 = v1434->regs;
  int v1438 = v1437[8];
  int * v1439 = v1434->regs;
  int v1447 = v1438 + 1;
  v1439[8] = v1447;
  struct StateT * v1441 = slot_90(v1434);
  return v1441;
}

struct StateT * slot_66(struct StateT * v1066) {
  int v1067 = v1066->timer;
  int v1075 = v1067 + 1;
  v1066->timer = v1075;
  int * v1069 = v1066->regs;
  int v1070 = v1069[8];
  int * v1071 = v1066->regs;
  int v1079 = v1070 + 1;
  v1071[8] = v1079;
  struct StateT * v1073 = slot_67(v1066);
  return v1073;
}

struct StateT * slot_140(struct StateT * v2250) {
  int v2251 = v2250->timer;
  int v2259 = v2251 + 1;
  v2250->timer = v2259;
  int * v2253 = v2250->regs;
  int v2254 = v2253[8];
  int * v2255 = v2250->regs;
  int v2263 = v2254 + 1;
  v2255[8] = v2263;
  struct StateT * v2257 = slot_141(v2250);
  return v2257;
}

struct StateT * slot_49(struct StateT * v794) {
  int v795 = v794->timer;
  int v803 = v795 + 1;
  v794->timer = v803;
  int * v797 = v794->regs;
  int v798 = v797[8];
  int * v799 = v794->regs;
  int v807 = v798 + 1;
  v799[8] = v807;
  struct StateT * v801 = slot_50(v794);
  return v801;
}

struct StateT * slot_216(struct StateT * v3466) {
  int v3467 = v3466->timer;
  int v3475 = v3467 + 1;
  v3466->timer = v3475;
  int * v3469 = v3466->regs;
  int v3470 = v3469[8];
  int * v3471 = v3466->regs;
  int v3479 = v3470 + 1;
  v3471[8] = v3479;
  struct StateT * v3473 = slot_217(v3466);
  return v3473;
}

struct StateT * slot_50(struct StateT * v810) {
  int v811 = v810->timer;
  int v819 = v811 + 1;
  v810->timer = v819;
  int * v813 = v810->regs;
  int v814 = v813[8];
  int * v815 = v810->regs;
  int v823 = v814 + 1;
  v815[8] = v823;
  struct StateT * v817 = slot_51(v810);
  return v817;
}

struct StateT * slot_37(struct StateT * v602) {
  int v603 = v602->timer;
  int v611 = v603 + 1;
  v602->timer = v611;
  int * v605 = v602->regs;
  int v606 = v605[8];
  int * v607 = v602->regs;
  int v615 = v606 + 1;
  v607[8] = v615;
  struct StateT * v609 = slot_38(v602);
  return v609;
}

struct StateT * slot_114(struct StateT * v1834) {
  int v1835 = v1834->timer;
  int v1843 = v1835 + 1;
  v1834->timer = v1843;
  int * v1837 = v1834->regs;
  int v1838 = v1837[8];
  int * v1839 = v1834->regs;
  int v1847 = v1838 + 1;
  v1839[8] = v1847;
  struct StateT * v1841 = slot_115(v1834);
  return v1841;
}

struct StateT * slot_135(struct StateT * v2170) {
  int v2171 = v2170->timer;
  int v2179 = v2171 + 1;
  v2170->timer = v2179;
  int * v2173 = v2170->regs;
  int v2174 = v2173[8];
  int * v2175 = v2170->regs;
  int v2183 = v2174 + 1;
  v2175[8] = v2183;
  struct StateT * v2177 = slot_136(v2170);
  return v2177;
}

struct StateT * slot_59(struct StateT * v954) {
  int v955 = v954->timer;
  int v963 = v955 + 1;
  v954->timer = v963;
  int * v957 = v954->regs;
  int v958 = v957[8];
  int * v959 = v954->regs;
  int v967 = v958 + 1;
  v959[8] = v967;
  struct StateT * v961 = slot_60(v954);
  return v961;
}

struct StateT * slot_192(struct StateT * v3082) {
  int v3083 = v3082->timer;
  int v3091 = v3083 + 1;
  v3082->timer = v3091;
  int * v3085 = v3082->regs;
  int v3086 = v3085[8];
  int * v3087 = v3082->regs;
  int v3095 = v3086 + 1;
  v3087[8] = v3095;
  struct StateT * v3089 = slot_193(v3082);
  return v3089;
}

struct StateT * slot_40(struct StateT * v650) {
  int v651 = v650->timer;
  int v659 = v651 + 1;
  v650->timer = v659;
  int * v653 = v650->regs;
  int v654 = v653[8];
  int * v655 = v650->regs;
  int v663 = v654 + 1;
  v655[8] = v663;
  struct StateT * v657 = slot_41(v650);
  return v657;
}

struct StateT * slot_48(struct StateT * v778) {
  int v779 = v778->timer;
  int v787 = v779 + 1;
  v778->timer = v787;
  int * v781 = v778->regs;
  int v782 = v781[8];
  int * v783 = v778->regs;
  int v791 = v782 + 1;
  v783[8] = v791;
  struct StateT * v785 = slot_49(v778);
  return v785;
}

struct StateT * slot_77(struct StateT * v1242) {
  int v1243 = v1242->timer;
  int v1251 = v1243 + 1;
  v1242->timer = v1251;
  int * v1245 = v1242->regs;
  int v1246 = v1245[8];
  int * v1247 = v1242->regs;
  int v1255 = v1246 + 1;
  v1247[8] = v1255;
  struct StateT * v1249 = slot_78(v1242);
  return v1249;
}

struct StateT * slot_85(struct StateT * v1370) {
  int v1371 = v1370->timer;
  int v1379 = v1371 + 1;
  v1370->timer = v1379;
  int * v1373 = v1370->regs;
  int v1374 = v1373[8];
  int * v1375 = v1370->regs;
  int v1383 = v1374 + 1;
  v1375[8] = v1383;
  struct StateT * v1377 = slot_86(v1370);
  return v1377;
}

struct StateT * slot_75(struct StateT * v1210) {
  int v1211 = v1210->timer;
  int v1219 = v1211 + 1;
  v1210->timer = v1219;
  int * v1213 = v1210->regs;
  int v1214 = v1213[8];
  int * v1215 = v1210->regs;
  int v1223 = v1214 + 1;
  v1215[8] = v1223;
  struct StateT * v1217 = slot_76(v1210);
  return v1217;
}

struct StateT * slot_72(struct StateT * v1162) {
  int v1163 = v1162->timer;
  int v1171 = v1163 + 1;
  v1162->timer = v1171;
  int * v1165 = v1162->regs;
  int v1166 = v1165[8];
  int * v1167 = v1162->regs;
  int v1175 = v1166 + 1;
  v1167[8] = v1175;
  struct StateT * v1169 = slot_73(v1162);
  return v1169;
}

struct StateT * slot_119(struct StateT * v1914) {
  int v1915 = v1914->timer;
  int v1923 = v1915 + 1;
  v1914->timer = v1923;
  int * v1917 = v1914->regs;
  int v1918 = v1917[8];
  int * v1919 = v1914->regs;
  int v1927 = v1918 + 1;
  v1919[8] = v1927;
  struct StateT * v1921 = slot_120(v1914);
  return v1921;
}

struct StateT * slot_71(struct StateT * v1146) {
  int v1147 = v1146->timer;
  int v1155 = v1147 + 1;
  v1146->timer = v1155;
  int * v1149 = v1146->regs;
  int v1150 = v1149[8];
  int * v1151 = v1146->regs;
  int v1159 = v1150 + 1;
  v1151[8] = v1159;
  struct StateT * v1153 = slot_72(v1146);
  return v1153;
}

struct StateT * slot_101(struct StateT * v1626) {
  int v1627 = v1626->timer;
  int v1635 = v1627 + 1;
  v1626->timer = v1635;
  int * v1629 = v1626->regs;
  int v1630 = v1629[8];
  int * v1631 = v1626->regs;
  int v1639 = v1630 + 1;
  v1631[8] = v1639;
  struct StateT * v1633 = slot_102(v1626);
  return v1633;
}

struct StateT * slot_108(struct StateT * v1738) {
  int v1739 = v1738->timer;
  int v1747 = v1739 + 1;
  v1738->timer = v1747;
  int * v1741 = v1738->regs;
  int v1742 = v1741[8];
  int * v1743 = v1738->regs;
  int v1751 = v1742 + 1;
  v1743[8] = v1751;
  struct StateT * v1745 = slot_109(v1738);
  return v1745;
}

struct StateT * slot_116(struct StateT * v1866) {
  int v1867 = v1866->timer;
  int v1875 = v1867 + 1;
  v1866->timer = v1875;
  int * v1869 = v1866->regs;
  int v1870 = v1869[8];
  int * v1871 = v1866->regs;
  int v1879 = v1870 + 1;
  v1871[8] = v1879;
  struct StateT * v1873 = slot_117(v1866);
  return v1873;
}

struct StateT * slot_93(struct StateT * v1498) {
  int v1499 = v1498->timer;
  int v1507 = v1499 + 1;
  v1498->timer = v1507;
  int * v1501 = v1498->regs;
  int v1502 = v1501[8];
  int * v1503 = v1498->regs;
  int v1511 = v1502 + 1;
  v1503[8] = v1511;
  struct StateT * v1505 = slot_94(v1498);
  return v1505;
}

struct StateT * slot_88(struct StateT * v1418) {
  int v1419 = v1418->timer;
  int v1427 = v1419 + 1;
  v1418->timer = v1427;
  int * v1421 = v1418->regs;
  int v1422 = v1421[8];
  int * v1423 = v1418->regs;
  int v1431 = v1422 + 1;
  v1423[8] = v1431;
  struct StateT * v1425 = slot_89(v1418);
  return v1425;
}

struct StateT * slot_96(struct StateT * v1546) {
  int v1547 = v1546->timer;
  int v1555 = v1547 + 1;
  v1546->timer = v1555;
  int * v1549 = v1546->regs;
  int v1550 = v1549[8];
  int * v1551 = v1546->regs;
  int v1559 = v1550 + 1;
  v1551[8] = v1559;
  struct StateT * v1553 = slot_97(v1546);
  return v1553;
}

struct StateT * slot_215(struct StateT * v3450) {
  int v3451 = v3450->timer;
  int v3459 = v3451 + 1;
  v3450->timer = v3459;
  int * v3453 = v3450->regs;
  int v3454 = v3453[8];
  int * v3455 = v3450->regs;
  int v3463 = v3454 + 1;
  v3455[8] = v3463;
  struct StateT * v3457 = slot_216(v3450);
  return v3457;
}

struct StateT * slot_45(struct StateT * v730) {
  int v731 = v730->timer;
  int v739 = v731 + 1;
  v730->timer = v739;
  int * v733 = v730->regs;
  int v734 = v733[8];
  int * v735 = v730->regs;
  int v743 = v734 + 1;
  v735[8] = v743;
  struct StateT * v737 = slot_46(v730);
  return v737;
}

struct StateT * slot_218(struct StateT * v3498) {
  int v3499 = v3498->timer;
  int v3507 = v3499 + 1;
  v3498->timer = v3507;
  int * v3501 = v3498->regs;
  int v3502 = v3501[8];
  int * v3503 = v3498->regs;
  int v3511 = v3502 + 1;
  v3503[8] = v3511;
  struct StateT * v3505 = slot_219(v3498);
  return v3505;
}

struct StateT * slot_220(struct StateT * v3530) {
  int v3531 = v3530->timer;
  int v3539 = v3531 + 1;
  v3530->timer = v3539;
  int * v3533 = v3530->regs;
  int v3534 = v3533[8];
  int * v3535 = v3530->regs;
  int v3543 = v3534 + 1;
  v3535[8] = v3543;
  struct StateT * v3537 = slot_221(v3530);
  return v3537;
}

struct StateT * slot_134(struct StateT * v2154) {
  int v2155 = v2154->timer;
  int v2163 = v2155 + 1;
  v2154->timer = v2163;
  int * v2157 = v2154->regs;
  int v2158 = v2157[8];
  int * v2159 = v2154->regs;
  int v2167 = v2158 + 1;
  v2159[8] = v2167;
  struct StateT * v2161 = slot_135(v2154);
  return v2161;
}

struct StateT * slot_175(struct StateT * v2810) {
  int v2811 = v2810->timer;
  int v2819 = v2811 + 1;
  v2810->timer = v2819;
  int * v2813 = v2810->regs;
  int v2814 = v2813[8];
  int * v2815 = v2810->regs;
  int v2823 = v2814 + 1;
  v2815[8] = v2823;
  struct StateT * v2817 = slot_176(v2810);
  return v2817;
}

struct StateT * slot_69(struct StateT * v1114) {
  int v1115 = v1114->timer;
  int v1123 = v1115 + 1;
  v1114->timer = v1123;
  int * v1117 = v1114->regs;
  int v1118 = v1117[8];
  int * v1119 = v1114->regs;
  int v1127 = v1118 + 1;
  v1119[8] = v1127;
  struct StateT * v1121 = slot_70(v1114);
  return v1121;
}

struct StateT * slot_202(struct StateT * v3242) {
  int v3243 = v3242->timer;
  int v3251 = v3243 + 1;
  v3242->timer = v3251;
  int * v3245 = v3242->regs;
  int v3246 = v3245[8];
  int * v3247 = v3242->regs;
  int v3255 = v3246 + 1;
  v3247[8] = v3255;
  struct StateT * v3249 = slot_203(v3242);
  return v3249;
}

struct StateT * slot_188(struct StateT * v3018) {
  int v3019 = v3018->timer;
  int v3027 = v3019 + 1;
  v3018->timer = v3027;
  int * v3021 = v3018->regs;
  int v3022 = v3021[8];
  int * v3023 = v3018->regs;
  int v3031 = v3022 + 1;
  v3023[8] = v3031;
  struct StateT * v3025 = slot_189(v3018);
  return v3025;
}

struct StateT * slot_138(struct StateT * v2218) {
  int v2219 = v2218->timer;
  int v2227 = v2219 + 1;
  v2218->timer = v2227;
  int * v2221 = v2218->regs;
  int v2222 = v2221[8];
  int * v2223 = v2218->regs;
  int v2231 = v2222 + 1;
  v2223[8] = v2231;
  struct StateT * v2225 = slot_139(v2218);
  return v2225;
}

struct StateT * slot_186(struct StateT * v2986) {
  int v2987 = v2986->timer;
  int v2995 = v2987 + 1;
  v2986->timer = v2995;
  int * v2989 = v2986->regs;
  int v2990 = v2989[8];
  int * v2991 = v2986->regs;
  int v2999 = v2990 + 1;
  v2991[8] = v2999;
  struct StateT * v2993 = slot_187(v2986);
  return v2993;
}

struct StateT * slot_102(struct StateT * v1642) {
  int v1643 = v1642->timer;
  int v1651 = v1643 + 1;
  v1642->timer = v1651;
  int * v1645 = v1642->regs;
  int v1646 = v1645[8];
  int * v1647 = v1642->regs;
  int v1655 = v1646 + 1;
  v1647[8] = v1655;
  struct StateT * v1649 = slot_103(v1642);
  return v1649;
}

struct StateT * slot_145(struct StateT * v2330) {
  int v2331 = v2330->timer;
  int v2339 = v2331 + 1;
  v2330->timer = v2339;
  int * v2333 = v2330->regs;
  int v2334 = v2333[8];
  int * v2335 = v2330->regs;
  int v2343 = v2334 + 1;
  v2335[8] = v2343;
  struct StateT * v2337 = slot_146(v2330);
  return v2337;
}

struct StateT * slot_110(struct StateT * v1770) {
  int v1771 = v1770->timer;
  int v1779 = v1771 + 1;
  v1770->timer = v1779;
  int * v1773 = v1770->regs;
  int v1774 = v1773[8];
  int * v1775 = v1770->regs;
  int v1783 = v1774 + 1;
  v1775[8] = v1783;
  struct StateT * v1777 = slot_111(v1770);
  return v1777;
}

struct StateT * slot_196(struct StateT * v3146) {
  int v3147 = v3146->timer;
  int v3155 = v3147 + 1;
  v3146->timer = v3155;
  int * v3149 = v3146->regs;
  int v3150 = v3149[8];
  int * v3151 = v3146->regs;
  int v3159 = v3150 + 1;
  v3151[8] = v3159;
  struct StateT * v3153 = slot_197(v3146);
  return v3153;
}

struct StateT * slot_208(struct StateT * v3338) {
  int v3339 = v3338->timer;
  int v3347 = v3339 + 1;
  v3338->timer = v3347;
  int * v3341 = v3338->regs;
  int v3342 = v3341[8];
  int * v3343 = v3338->regs;
  int v3351 = v3342 + 1;
  v3343[8] = v3351;
  struct StateT * v3345 = slot_209(v3338);
  return v3345;
}

struct StateT * slot_172(struct StateT * v2762) {
  int v2763 = v2762->timer;
  int v2771 = v2763 + 1;
  v2762->timer = v2771;
  int * v2765 = v2762->regs;
  int v2766 = v2765[8];
  int * v2767 = v2762->regs;
  int v2775 = v2766 + 1;
  v2767[8] = v2775;
  struct StateT * v2769 = slot_173(v2762);
  return v2769;
}

struct StateT * slot_131(struct StateT * v2106) {
  int v2107 = v2106->timer;
  int v2115 = v2107 + 1;
  v2106->timer = v2115;
  int * v2109 = v2106->regs;
  int v2110 = v2109[8];
  int * v2111 = v2106->regs;
  int v2119 = v2110 + 1;
  v2111[8] = v2119;
  struct StateT * v2113 = slot_132(v2106);
  return v2113;
}

struct StateT * slot_8(struct StateT * v138) {
  int v139 = v138->timer;
  int v147 = v139 + 1;
  v138->timer = v147;
  int * v141 = v138->regs;
  int v142 = v141[8];
  int * v143 = v138->regs;
  int v151 = v142 + 1;
  v143[8] = v151;
  struct StateT * v145 = slot_9(v138);
  return v145;
}

struct StateT * slot_180(struct StateT * v2890) {
  int v2891 = v2890->timer;
  int v2899 = v2891 + 1;
  v2890->timer = v2899;
  int * v2893 = v2890->regs;
  int v2894 = v2893[8];
  int * v2895 = v2890->regs;
  int v2903 = v2894 + 1;
  v2895[8] = v2903;
  struct StateT * v2897 = slot_181(v2890);
  return v2897;
}

struct StateT * slot_203(struct StateT * v3258) {
  int v3259 = v3258->timer;
  int v3267 = v3259 + 1;
  v3258->timer = v3267;
  int * v3261 = v3258->regs;
  int v3262 = v3261[8];
  int * v3263 = v3258->regs;
  int v3271 = v3262 + 1;
  v3263[8] = v3271;
  struct StateT * v3265 = slot_204(v3258);
  return v3265;
}

struct StateT * slot_190(struct StateT * v3050) {
  int v3051 = v3050->timer;
  int v3059 = v3051 + 1;
  v3050->timer = v3059;
  int * v3053 = v3050->regs;
  int v3054 = v3053[8];
  int * v3055 = v3050->regs;
  int v3063 = v3054 + 1;
  v3055[8] = v3063;
  struct StateT * v3057 = slot_191(v3050);
  return v3057;
}

struct StateT * slot_157(struct StateT * v2522) {
  int v2523 = v2522->timer;
  int v2531 = v2523 + 1;
  v2522->timer = v2531;
  int * v2525 = v2522->regs;
  int v2526 = v2525[8];
  int * v2527 = v2522->regs;
  int v2535 = v2526 + 1;
  v2527[8] = v2535;
  struct StateT * v2529 = slot_158(v2522);
  return v2529;
}

struct StateT * slot_200(struct StateT * v3210) {
  int v3211 = v3210->timer;
  int v3219 = v3211 + 1;
  v3210->timer = v3219;
  int * v3213 = v3210->regs;
  int v3214 = v3213[8];
  int * v3215 = v3210->regs;
  int v3223 = v3214 + 1;
  v3215[8] = v3223;
  struct StateT * v3217 = slot_201(v3210);
  return v3217;
}

struct StateT * slot_173(struct StateT * v2778) {
  int v2779 = v2778->timer;
  int v2787 = v2779 + 1;
  v2778->timer = v2787;
  int * v2781 = v2778->regs;
  int v2782 = v2781[8];
  int * v2783 = v2778->regs;
  int v2791 = v2782 + 1;
  v2783[8] = v2791;
  struct StateT * v2785 = slot_174(v2778);
  return v2785;
}

struct StateT * slot_149(struct StateT * v2394) {
  int v2395 = v2394->timer;
  int v2403 = v2395 + 1;
  v2394->timer = v2403;
  int * v2397 = v2394->regs;
  int v2398 = v2397[8];
  int * v2399 = v2394->regs;
  int v2407 = v2398 + 1;
  v2399[8] = v2407;
  struct StateT * v2401 = slot_150(v2394);
  return v2401;
}

struct StateT * slot_5(struct StateT * v93) {
  int v94 = v93->timer;
  int v100 = v94 + 1;
  v93->timer = v100;
  int * v96 = v93->regs;
  v96[8] = 0;
  struct StateT * v98 = slot_6(v93);
  return v98;
}

struct StateT * slot_104(struct StateT * v1674) {
  int v1675 = v1674->timer;
  int v1683 = v1675 + 1;
  v1674->timer = v1683;
  int * v1677 = v1674->regs;
  int v1678 = v1677[8];
  int * v1679 = v1674->regs;
  int v1687 = v1678 + 1;
  v1679[8] = v1687;
  struct StateT * v1681 = slot_105(v1674);
  return v1681;
}

struct StateT * slot_54(struct StateT * v874) {
  int v875 = v874->timer;
  int v883 = v875 + 1;
  v874->timer = v883;
  int * v877 = v874->regs;
  int v878 = v877[8];
  int * v879 = v874->regs;
  int v887 = v878 + 1;
  v879[8] = v887;
  struct StateT * v881 = slot_55(v874);
  return v881;
}

struct StateT * slot_26(struct StateT * v426) {
  int v427 = v426->timer;
  int v435 = v427 + 1;
  v426->timer = v435;
  int * v429 = v426->regs;
  int v430 = v429[8];
  int * v431 = v426->regs;
  int v439 = v430 + 1;
  v431[8] = v439;
  struct StateT * v433 = slot_27(v426);
  return v433;
}

struct StateT * slot_206(struct StateT * v3306) {
  int v3307 = v3306->timer;
  int v3315 = v3307 + 1;
  v3306->timer = v3315;
  int * v3309 = v3306->regs;
  int v3310 = v3309[8];
  int * v3311 = v3306->regs;
  int v3319 = v3310 + 1;
  v3311[8] = v3319;
  struct StateT * v3313 = slot_207(v3306);
  return v3313;
}

struct StateT * slot_169(struct StateT * v2714) {
  int v2715 = v2714->timer;
  int v2723 = v2715 + 1;
  v2714->timer = v2723;
  int * v2717 = v2714->regs;
  int v2718 = v2717[8];
  int * v2719 = v2714->regs;
  int v2727 = v2718 + 1;
  v2719[8] = v2727;
  struct StateT * v2721 = slot_170(v2714);
  return v2721;
}

struct StateT * slot_64(struct StateT * v1034) {
  int v1035 = v1034->timer;
  int v1043 = v1035 + 1;
  v1034->timer = v1043;
  int * v1037 = v1034->regs;
  int v1038 = v1037[8];
  int * v1039 = v1034->regs;
  int v1047 = v1038 + 1;
  v1039[8] = v1047;
  struct StateT * v1041 = slot_65(v1034);
  return v1041;
}

struct StateT * slot_170(struct StateT * v2730) {
  int v2731 = v2730->timer;
  int v2739 = v2731 + 1;
  v2730->timer = v2739;
  int * v2733 = v2730->regs;
  int v2734 = v2733[8];
  int * v2735 = v2730->regs;
  int v2743 = v2734 + 1;
  v2735[8] = v2743;
  struct StateT * v2737 = slot_171(v2730);
  return v2737;
}

struct StateT * slot_14(struct StateT * v234) {
  int v235 = v234->timer;
  int v243 = v235 + 1;
  v234->timer = v243;
  int * v237 = v234->regs;
  int v238 = v237[8];
  int * v239 = v234->regs;
  int v247 = v238 + 1;
  v239[8] = v247;
  struct StateT * v241 = slot_15(v234);
  return v241;
}

struct StateT * slot_53(struct StateT * v858) {
  int v859 = v858->timer;
  int v867 = v859 + 1;
  v858->timer = v867;
  int * v861 = v858->regs;
  int v862 = v861[8];
  int * v863 = v858->regs;
  int v871 = v862 + 1;
  v863[8] = v871;
  struct StateT * v865 = slot_54(v858);
  return v865;
}

struct StateT * slot_80(struct StateT * v1290) {
  int v1291 = v1290->timer;
  int v1299 = v1291 + 1;
  v1290->timer = v1299;
  int * v1293 = v1290->regs;
  int v1294 = v1293[8];
  int * v1295 = v1290->regs;
  int v1303 = v1294 + 1;
  v1295[8] = v1303;
  struct StateT * v1297 = slot_81(v1290);
  return v1297;
}

struct StateT * slot_44(struct StateT * v714) {
  int v715 = v714->timer;
  int v723 = v715 + 1;
  v714->timer = v723;
  int * v717 = v714->regs;
  int v718 = v717[8];
  int * v719 = v714->regs;
  int v727 = v718 + 1;
  v719[8] = v727;
  struct StateT * v721 = slot_45(v714);
  return v721;
}

struct StateT * slot_137(struct StateT * v2202) {
  int v2203 = v2202->timer;
  int v2211 = v2203 + 1;
  v2202->timer = v2211;
  int * v2205 = v2202->regs;
  int v2206 = v2205[8];
  int * v2207 = v2202->regs;
  int v2215 = v2206 + 1;
  v2207[8] = v2215;
  struct StateT * v2209 = slot_138(v2202);
  return v2209;
}

struct StateT * slot_122(struct StateT * v1962) {
  int v1963 = v1962->timer;
  int v1971 = v1963 + 1;
  v1962->timer = v1971;
  int * v1965 = v1962->regs;
  int v1966 = v1965[8];
  int * v1967 = v1962->regs;
  int v1975 = v1966 + 1;
  v1967[8] = v1975;
  struct StateT * v1969 = slot_123(v1962);
  return v1969;
}

struct StateT * slot_99(struct StateT * v1594) {
  int v1595 = v1594->timer;
  int v1603 = v1595 + 1;
  v1594->timer = v1603;
  int * v1597 = v1594->regs;
  int v1598 = v1597[8];
  int * v1599 = v1594->regs;
  int v1607 = v1598 + 1;
  v1599[8] = v1607;
  struct StateT * v1601 = slot_100(v1594);
  return v1601;
}

struct StateT * slot_179(struct StateT * v2874) {
  int v2875 = v2874->timer;
  int v2883 = v2875 + 1;
  v2874->timer = v2883;
  int * v2877 = v2874->regs;
  int v2878 = v2877[8];
  int * v2879 = v2874->regs;
  int v2887 = v2878 + 1;
  v2879[8] = v2887;
  struct StateT * v2881 = slot_180(v2874);
  return v2881;
}

struct StateT * slot_219(struct StateT * v3514) {
  int v3515 = v3514->timer;
  int v3523 = v3515 + 1;
  v3514->timer = v3523;
  int * v3517 = v3514->regs;
  int v3518 = v3517[8];
  int * v3519 = v3514->regs;
  int v3527 = v3518 + 1;
  v3519[8] = v3527;
  struct StateT * v3521 = slot_220(v3514);
  return v3521;
}

struct StateT * slot_36(struct StateT * v586) {
  int v587 = v586->timer;
  int v595 = v587 + 1;
  v586->timer = v595;
  int * v589 = v586->regs;
  int v590 = v589[8];
  int * v591 = v586->regs;
  int v599 = v590 + 1;
  v591[8] = v599;
  struct StateT * v593 = slot_37(v586);
  return v593;
}

struct StateT * slot_57(struct StateT * v922) {
  int v923 = v922->timer;
  int v931 = v923 + 1;
  v922->timer = v931;
  int * v925 = v922->regs;
  int v926 = v925[8];
  int * v927 = v922->regs;
  int v935 = v926 + 1;
  v927[8] = v935;
  struct StateT * v929 = slot_58(v922);
  return v929;
}

struct StateT * slot_62(struct StateT * v1002) {
  int v1003 = v1002->timer;
  int v1011 = v1003 + 1;
  v1002->timer = v1011;
  int * v1005 = v1002->regs;
  int v1006 = v1005[8];
  int * v1007 = v1002->regs;
  int v1015 = v1006 + 1;
  v1007[8] = v1015;
  struct StateT * v1009 = slot_63(v1002);
  return v1009;
}

struct StateT * slot_22(struct StateT * v362) {
  int v363 = v362->timer;
  int v371 = v363 + 1;
  v362->timer = v371;
  int * v365 = v362->regs;
  int v366 = v365[8];
  int * v367 = v362->regs;
  int v375 = v366 + 1;
  v367[8] = v375;
  struct StateT * v369 = slot_23(v362);
  return v369;
}

struct StateT * slot_139(struct StateT * v2234) {
  int v2235 = v2234->timer;
  int v2243 = v2235 + 1;
  v2234->timer = v2243;
  int * v2237 = v2234->regs;
  int v2238 = v2237[8];
  int * v2239 = v2234->regs;
  int v2247 = v2238 + 1;
  v2239[8] = v2247;
  struct StateT * v2241 = slot_140(v2234);
  return v2241;
}

struct StateT * slot_221(struct StateT * v3546) {
  int v3547 = v3546->timer;
  int v3555 = v3547 + 1;
  v3546->timer = v3555;
  int * v3549 = v3546->regs;
  int v3550 = v3549[8];
  int * v3551 = v3546->regs;
  int v3559 = v3550 + 1;
  v3551[8] = v3559;
  struct StateT * v3553 = slot_222(v3546);
  return v3553;
}

struct StateT * slot_23(struct StateT * v378) {
  int v379 = v378->timer;
  int v387 = v379 + 1;
  v378->timer = v387;
  int * v381 = v378->regs;
  int v382 = v381[8];
  int * v383 = v378->regs;
  int v391 = v382 + 1;
  v383[8] = v391;
  struct StateT * v385 = slot_24(v378);
  return v385;
}

struct StateT * slot_153(struct StateT * v2458) {
  int v2459 = v2458->timer;
  int v2467 = v2459 + 1;
  v2458->timer = v2467;
  int * v2461 = v2458->regs;
  int v2462 = v2461[8];
  int * v2463 = v2458->regs;
  int v2471 = v2462 + 1;
  v2463[8] = v2471;
  struct StateT * v2465 = slot_154(v2458);
  return v2465;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v49 = v41 + 1;
  v40->timer = v49;
  int * v43 = v40->regs;
  int v44 = v43[6];
  int * v45 = v40->regs;
  int v53 = v44 & 7;
  v45[6] = v53;
  struct StateT * v47 = slot_3(v40);
  return v47;
}

struct StateT * slot_86(struct StateT * v1386) {
  int v1387 = v1386->timer;
  int v1395 = v1387 + 1;
  v1386->timer = v1395;
  int * v1389 = v1386->regs;
  int v1390 = v1389[8];
  int * v1391 = v1386->regs;
  int v1399 = v1390 + 1;
  v1391[8] = v1399;
  struct StateT * v1393 = slot_87(v1386);
  return v1393;
}

struct StateT * slot_129(struct StateT * v2074) {
  int v2075 = v2074->timer;
  int v2083 = v2075 + 1;
  v2074->timer = v2083;
  int * v2077 = v2074->regs;
  int v2078 = v2077[8];
  int * v2079 = v2074->regs;
  int v2087 = v2078 + 1;
  v2079[8] = v2087;
  struct StateT * v2081 = slot_130(v2074);
  return v2081;
}

struct StateT * slot_158(struct StateT * v2538) {
  int v2539 = v2538->timer;
  int v2547 = v2539 + 1;
  v2538->timer = v2547;
  int * v2541 = v2538->regs;
  int v2542 = v2541[8];
  int * v2543 = v2538->regs;
  int v2551 = v2542 + 1;
  v2543[8] = v2551;
  struct StateT * v2545 = slot_159(v2538);
  return v2545;
}

struct StateT * slot_100(struct StateT * v1610) {
  int v1611 = v1610->timer;
  int v1619 = v1611 + 1;
  v1610->timer = v1619;
  int * v1613 = v1610->regs;
  int v1614 = v1613[8];
  int * v1615 = v1610->regs;
  int v1623 = v1614 + 1;
  v1615[8] = v1623;
  struct StateT * v1617 = slot_101(v1610);
  return v1617;
}

struct StateT * slot_127(struct StateT * v2042) {
  int v2043 = v2042->timer;
  int v2051 = v2043 + 1;
  v2042->timer = v2051;
  int * v2045 = v2042->regs;
  int v2046 = v2045[8];
  int * v2047 = v2042->regs;
  int v2055 = v2046 + 1;
  v2047[8] = v2055;
  struct StateT * v2049 = slot_128(v2042);
  return v2049;
}

struct StateT * slot_217(struct StateT * v3482) {
  int v3483 = v3482->timer;
  int v3491 = v3483 + 1;
  v3482->timer = v3491;
  int * v3485 = v3482->regs;
  int v3486 = v3485[8];
  int * v3487 = v3482->regs;
  int v3495 = v3486 + 1;
  v3487[8] = v3495;
  struct StateT * v3489 = slot_218(v3482);
  return v3489;
}

struct StateT * slot_13(struct StateT * v218) {
  int v219 = v218->timer;
  int v227 = v219 + 1;
  v218->timer = v227;
  int * v221 = v218->regs;
  int v222 = v221[8];
  int * v223 = v218->regs;
  int v231 = v222 + 1;
  v223[8] = v231;
  struct StateT * v225 = slot_14(v218);
  return v225;
}

struct StateT * slot_111(struct StateT * v1786) {
  int v1787 = v1786->timer;
  int v1795 = v1787 + 1;
  v1786->timer = v1795;
  int * v1789 = v1786->regs;
  int v1790 = v1789[8];
  int * v1791 = v1786->regs;
  int v1799 = v1790 + 1;
  v1791[8] = v1799;
  struct StateT * v1793 = slot_112(v1786);
  return v1793;
}

struct StateT * slot_109(struct StateT * v1754) {
  int v1755 = v1754->timer;
  int v1763 = v1755 + 1;
  v1754->timer = v1763;
  int * v1757 = v1754->regs;
  int v1758 = v1757[8];
  int * v1759 = v1754->regs;
  int v1767 = v1758 + 1;
  v1759[8] = v1767;
  struct StateT * v1761 = slot_110(v1754);
  return v1761;
}

struct StateT * slot_174(struct StateT * v2794) {
  int v2795 = v2794->timer;
  int v2803 = v2795 + 1;
  v2794->timer = v2803;
  int * v2797 = v2794->regs;
  int v2798 = v2797[8];
  int * v2799 = v2794->regs;
  int v2807 = v2798 + 1;
  v2799[8] = v2807;
  struct StateT * v2801 = slot_175(v2794);
  return v2801;
}

struct StateT * slot_147(struct StateT * v2362) {
  int v2363 = v2362->timer;
  int v2371 = v2363 + 1;
  v2362->timer = v2371;
  int * v2365 = v2362->regs;
  int v2366 = v2365[8];
  int * v2367 = v2362->regs;
  int v2375 = v2366 + 1;
  v2367[8] = v2375;
  struct StateT * v2369 = slot_148(v2362);
  return v2369;
}

struct StateT * slot_42(struct StateT * v682) {
  int v683 = v682->timer;
  int v691 = v683 + 1;
  v682->timer = v691;
  int * v685 = v682->regs;
  int v686 = v685[8];
  int * v687 = v682->regs;
  int v695 = v686 + 1;
  v687[8] = v695;
  struct StateT * v689 = slot_43(v682);
  return v689;
}

struct StateT * slot_224(struct StateT * v3594) {
  int v3595 = v3594->timer;
  int v3603 = v3595 + 1;
  v3594->timer = v3603;
  int * v3597 = v3594->regs;
  int v3598 = v3597[8];
  int * v3599 = v3594->regs;
  int v3607 = v3598 + 1;
  v3599[8] = v3607;
  struct StateT * v3601 = slot_225(v3594);
  return v3601;
}

struct StateT * slot_163(struct StateT * v2618) {
  int v2619 = v2618->timer;
  int v2627 = v2619 + 1;
  v2618->timer = v2627;
  int * v2621 = v2618->regs;
  int v2622 = v2621[8];
  int * v2623 = v2618->regs;
  int v2631 = v2622 + 1;
  v2623[8] = v2631;
  struct StateT * v2625 = slot_164(v2618);
  return v2625;
}

struct StateT * slot_184(struct StateT * v2954) {
  int v2955 = v2954->timer;
  int v2963 = v2955 + 1;
  v2954->timer = v2963;
  int * v2957 = v2954->regs;
  int v2958 = v2957[8];
  int * v2959 = v2954->regs;
  int v2967 = v2958 + 1;
  v2959[8] = v2967;
  struct StateT * v2961 = slot_185(v2954);
  return v2961;
}

struct StateT * slot_204(struct StateT * v3274) {
  int v3275 = v3274->timer;
  int v3283 = v3275 + 1;
  v3274->timer = v3283;
  int * v3277 = v3274->regs;
  int v3278 = v3277[8];
  int * v3279 = v3274->regs;
  int v3287 = v3278 + 1;
  v3279[8] = v3287;
  struct StateT * v3281 = slot_205(v3274);
  return v3281;
}

struct StateT * slot_194(struct StateT * v3114) {
  int v3115 = v3114->timer;
  int v3123 = v3115 + 1;
  v3114->timer = v3123;
  int * v3117 = v3114->regs;
  int v3118 = v3117[8];
  int * v3119 = v3114->regs;
  int v3127 = v3118 + 1;
  v3119[8] = v3127;
  struct StateT * v3121 = slot_195(v3114);
  return v3121;
}

struct StateT * slot_165(struct StateT * v2650) {
  int v2651 = v2650->timer;
  int v2659 = v2651 + 1;
  v2650->timer = v2659;
  int * v2653 = v2650->regs;
  int v2654 = v2653[8];
  int * v2655 = v2650->regs;
  int v2663 = v2654 + 1;
  v2655[8] = v2663;
  struct StateT * v2657 = slot_166(v2650);
  return v2657;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v1882) {
  int v1883 = v1882->timer;
  int v1891 = v1883 + 1;
  v1882->timer = v1891;
  int * v1885 = v1882->regs;
  int v1886 = v1885[8];
  int * v1887 = v1882->regs;
  int v1895 = v1886 + 1;
  v1887[8] = v1895;
  struct StateT * v1889 = slot_118(v1882);
  return v1889;
}

struct StateT * slot_90(struct StateT * v1450) {
  int v1451 = v1450->timer;
  int v1459 = v1451 + 1;
  v1450->timer = v1459;
  int * v1453 = v1450->regs;
  int v1454 = v1453[8];
  int * v1455 = v1450->regs;
  int v1463 = v1454 + 1;
  v1455[8] = v1463;
  struct StateT * v1457 = slot_91(v1450);
  return v1457;
}

struct StateT * slot_11(struct StateT * v186) {
  int v187 = v186->timer;
  int v195 = v187 + 1;
  v186->timer = v195;
  int * v189 = v186->regs;
  int v190 = v189[8];
  int * v191 = v186->regs;
  int v199 = v190 + 1;
  v191[8] = v199;
  struct StateT * v193 = slot_12(v186);
  return v193;
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