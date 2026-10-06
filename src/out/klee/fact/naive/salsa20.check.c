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

struct StateT * slot_12(struct StateT * v225);
struct StateT * slot_228(struct StateT * v1375);
struct StateT * slot_143(struct StateT * v3439);
struct StateT * slot_120(struct StateT * v3081);
struct StateT * slot_226(struct StateT * v1311);
struct StateT * slot_167(struct StateT * v3816);
struct StateT * slot_268(struct StateT * v2703);
struct StateT * slot_152(struct StateT * v3585);
struct StateT * slot_231(struct StateT * v1471);
struct StateT * slot_199(struct StateT * v4320);
struct StateT * slot_252(struct StateT * v2151);
struct StateT * slot_92(struct StateT * v2241);
struct StateT * slot_232(struct StateT * v1506);
struct StateT * slot_269(struct StateT * v2739);
struct StateT * slot_31(struct StateT * v558);
struct StateT * slot_236(struct StateT * v1643);
struct StateT * slot_241(struct StateT * v1791);
struct StateT * slot_160(struct StateT * v3710);
struct StateT * slot_251(struct StateT * v2116);
struct StateT * slot_65(struct StateT * v1361);
struct StateT * slot_10(struct StateT * v187);
struct StateT * slot_150(struct StateT * v3551);
struct StateT * slot_74(struct StateT * v1659);
struct StateT * slot_262(struct StateT * v2499);
struct StateT * slot_107(struct StateT * v2758);
struct StateT * slot_136(struct StateT * v3335);
struct StateT * slot_84(struct StateT * v1963);
struct StateT * slot_28(struct StateT * v517);
struct StateT * slot_155(struct StateT * v3636);
struct StateT * slot_177(struct StateT * v3977);
struct StateT * slot_229(struct StateT * v1404);
struct StateT * slot_17(struct StateT * v314);
struct StateT * slot_181(struct StateT * v4038);
struct StateT * slot_197(struct StateT * v4289);
struct StateT * slot_207(struct StateT * v4440);
struct StateT * slot_156(struct StateT * v3651);
struct StateT * slot_154(struct StateT * v3619);
struct StateT * slot_68(struct StateT * v1455);
struct StateT * slot_260(struct StateT * v2432);
struct StateT * slot_105(struct StateT * v2689);
struct StateT * slot_27(struct StateT * v504);
struct StateT * slot_164(struct StateT * v3771);
struct StateT * slot_15(struct StateT * v276);
struct StateT * slot_133(struct StateT * v3286);
struct StateT * slot_56(struct StateT * v1073);
struct StateT * slot_244(struct StateT * v1882);
struct StateT * slot_222(struct StateT * v1180);
struct StateT * slot_34(struct StateT * v601);
struct StateT * slot_171(struct StateT * v3880);
struct StateT * slot_162(struct StateT * v3741);
struct StateT * slot_21(struct StateT * v390);
struct StateT * slot_239(struct StateT * v1732);
struct StateT * slot_118(struct StateT * v3052);
struct StateT * slot_121(struct StateT * v3097);
struct StateT * slot_144(struct StateT * v3455);
struct StateT * slot_267(struct StateT * v2670);
struct StateT * slot_201(struct StateT * v4350);
struct StateT * slot_94(struct StateT * v2313);
struct StateT * slot_63(struct StateT * v1295);
struct StateT * slot_146(struct StateT * v3484);
struct StateT * slot_24(struct StateT * v447);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v4260);
struct StateT * slot_125(struct StateT * v3157);
struct StateT * slot_254(struct StateT * v2222);
struct StateT * slot_148(struct StateT * v3517);
struct StateT * slot_126(struct StateT * v3171);
struct StateT * slot_223(struct StateT * v1215);
struct StateT * slot_79(struct StateT * v1805);
struct StateT * slot_237(struct StateT * v1676);
struct StateT * slot_41(struct StateT * v723);
struct StateT * slot_39(struct StateT * v685);
struct StateT * slot_142(struct StateT * v3425);
struct StateT * slot_60(struct StateT * v1199);
struct StateT * slot_238(struct StateT * v1704);
struct StateT * slot_112(struct StateT * v2937);
struct StateT * slot_256(struct StateT * v2294);
struct StateT * slot_272(struct StateT * v2846);
struct StateT * slot_47(struct StateT * v825);
struct StateT * slot_214(struct StateT * v927);
struct StateT * slot_29(struct StateT * v530);
struct StateT * slot_16(struct StateT * v295);
struct StateT * slot_245(struct StateT * v1912);
struct StateT * slot_113(struct StateT * v2968);
struct StateT * slot_151(struct StateT * v3568);
struct StateT * slot_7(struct StateT * v130);
struct StateT * slot_124(struct StateT * v3142);
struct StateT * slot_191(struct StateT * v4192);
struct StateT * slot_103(struct StateT * v2620);
struct StateT * slot_128(struct StateT * v3203);
struct StateT * slot_19(struct StateT * v352);
struct StateT * slot_87(struct StateT * v2065);
struct StateT * slot_67(struct StateT * v1423);
struct StateT * slot_81(struct StateT * v1867);
struct StateT * slot_95(struct StateT * v2349);
struct StateT * slot_115(struct StateT * v3007);
struct StateT * slot_78(struct StateT * v1776);
struct StateT * slot_32(struct StateT * v573);
struct StateT * slot_205(struct StateT * v4410);
struct StateT * slot_193(struct StateT * v4226);
struct StateT * slot_233(struct StateT * v1538);
struct StateT * slot_176(struct StateT * v3963);
struct StateT * slot_189(struct StateT * v4160);
struct StateT * slot_33(struct StateT * v588);
struct StateT * slot_35(struct StateT * v615);
struct StateT * slot_258(struct StateT * v2364);
struct StateT * slot_246(struct StateT * v1944);
struct StateT * slot_210(struct StateT * v4489);
struct StateT * slot_166(struct StateT * v3800);
struct StateT * slot_51(struct StateT * v910);
struct StateT * slot_52(struct StateT * v943);
struct StateT * slot_83(struct StateT * v1928);
struct StateT * slot_25(struct StateT * v466);
struct StateT * slot_209(struct StateT * v4473);
struct StateT * slot_3(struct StateT * v54);
struct StateT * slot_264(struct StateT * v2568);
struct StateT * slot_123(struct StateT * v3126);
struct StateT * slot_73(struct StateT * v1626);
struct StateT * slot_270(struct StateT * v2775);
struct StateT * slot_198(struct StateT * v4305);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v4128);
struct StateT * slot_97(struct StateT * v2416);
struct StateT * slot_182(struct StateT * v4053);
struct StateT * slot_38(struct StateT * v666);
struct StateT * slot_178(struct StateT * v3993);
struct StateT * slot_106(struct StateT * v2722);
struct StateT * slot_98(struct StateT * v2451);
struct StateT * slot_159(struct StateT * v3696);
struct StateT * slot_46(struct StateT * v810);
struct StateT * slot_212(struct StateT * v4519);
struct StateT * slot_132(struct StateT * v3269);
struct StateT * slot_130(struct StateT * v3236);
struct StateT * slot_211(struct StateT * v4505);
struct StateT * slot_20(struct StateT * v371);
struct StateT * slot_141(struct StateT * v3410);
struct StateT * slot_61(struct StateT * v1231);
struct StateT * slot_30(struct StateT * v543);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_18(struct StateT * v333);
struct StateT * slot_9(struct StateT * v168);
struct StateT * slot_183(struct StateT * v4067);
struct StateT * slot_240(struct StateT * v1762);
struct StateT * slot_247(struct StateT * v1978);
struct StateT * slot_43(struct StateT * v761);
struct StateT * slot_70(struct StateT * v1522);
struct StateT * slot_168(struct StateT * v3832);
struct StateT * slot_76(struct StateT * v1718);
struct StateT * slot_6(struct StateT * v111);
struct StateT * slot_225(struct StateT * v1279);
struct StateT * slot_55(struct StateT * v1042);
struct StateT * slot_213(struct StateT * v894);
struct StateT * slot_82(struct StateT * v1898);
struct StateT * slot_274(struct StateT * v2918);
struct StateT * slot_263(struct StateT * v2534);
struct StateT * slot_161(struct StateT * v3726);
struct StateT * slot_185(struct StateT * v4098);
struct StateT * slot_91(struct StateT * v2205);
struct StateT * slot_58(struct StateT * v1135);
struct StateT * slot_89(struct StateT * v2135);
struct StateT * slot_255(struct StateT * v2258);
struct StateT * slot_66(struct StateT * v1388);
struct StateT * slot_140(struct StateT * v3394);
struct StateT * slot_265(struct StateT * v2601);
struct StateT * slot_49(struct StateT * v859);
struct StateT * slot_216(struct StateT * v990);
struct StateT * slot_50(struct StateT * v874);
struct StateT * slot_37(struct StateT * v647);
struct StateT * slot_114(struct StateT * v2990);
struct StateT * slot_135(struct StateT * v3320);
struct StateT * slot_248(struct StateT * v2011);
struct StateT * slot_257(struct StateT * v2330);
struct StateT * slot_59(struct StateT * v1166);
struct StateT * slot_192(struct StateT * v4209);
struct StateT * slot_40(struct StateT * v704);
struct StateT * slot_48(struct StateT * v840);
struct StateT * slot_77(struct StateT * v1746);
struct StateT * slot_85(struct StateT * v1997);
struct StateT * slot_75(struct StateT * v1689);
struct StateT * slot_72(struct StateT * v1590);
struct StateT * slot_119(struct StateT * v3067);
struct StateT * slot_71(struct StateT * v1557);
struct StateT * slot_101(struct StateT * v2553);
struct StateT * slot_276(struct StateT * v2985);
struct StateT * slot_108(struct StateT * v2794);
struct StateT * slot_116(struct StateT * v3022);
struct StateT * slot_93(struct StateT * v2277);
struct StateT * slot_266(struct StateT * v2636);
struct StateT * slot_88(struct StateT * v2100);
struct StateT * slot_96(struct StateT * v2383);
struct StateT * slot_215(struct StateT * v960);
struct StateT * slot_234(struct StateT * v1574);
struct StateT * slot_45(struct StateT * v795);
struct StateT * slot_218(struct StateT * v1057);
struct StateT * slot_220(struct StateT * v1116);
struct StateT * slot_134(struct StateT * v3303);
struct StateT * slot_175(struct StateT * v3948);
struct StateT * slot_273(struct StateT * v2882);
struct StateT * slot_69(struct StateT * v1490);
struct StateT * slot_202(struct StateT * v4365);
struct StateT * slot_230(struct StateT * v1439);
struct StateT * slot_188(struct StateT * v4144);
struct StateT * slot_138(struct StateT * v3365);
struct StateT * slot_186(struct StateT * v4112);
struct StateT * slot_102(struct StateT * v2587);
struct StateT * slot_145(struct StateT * v3470);
struct StateT * slot_110(struct StateT * v2865);
struct StateT * slot_196(struct StateT * v4275);
struct StateT * slot_208(struct StateT * v4456);
struct StateT * slot_172(struct StateT * v3897);
struct StateT * slot_131(struct StateT * v3252);
struct StateT * slot_8(struct StateT * v149);
struct StateT * slot_180(struct StateT * v4022);
struct StateT * slot_203(struct StateT * v4379);
struct StateT * slot_190(struct StateT * v4176);
struct StateT * slot_157(struct StateT * v3665);
struct StateT * slot_242(struct StateT * v1819);
struct StateT * slot_200(struct StateT * v4334);
struct StateT * slot_243(struct StateT * v1851);
struct StateT * slot_173(struct StateT * v3914);
struct StateT * slot_149(struct StateT * v3534);
struct StateT * slot_5(struct StateT * v92);
struct StateT * slot_104(struct StateT * v2655);
struct StateT * slot_235(struct StateT * v1607);
struct StateT * slot_275(struct StateT * v2954);
struct StateT * slot_54(struct StateT * v1006);
struct StateT * slot_26(struct StateT * v485);
struct StateT * slot_206(struct StateT * v4424);
struct StateT * slot_227(struct StateT * v1345);
struct StateT * slot_169(struct StateT * v3848);
struct StateT * slot_253(struct StateT * v2186);
struct StateT * slot_64(struct StateT * v1330);
struct StateT * slot_170(struct StateT * v3864);
struct StateT * slot_14(struct StateT * v263);
struct StateT * slot_53(struct StateT * v973);
struct StateT * slot_80(struct StateT * v1835);
struct StateT * slot_44(struct StateT * v780);
struct StateT * slot_261(struct StateT * v2466);
struct StateT * slot_137(struct StateT * v3349);
struct StateT * slot_122(struct StateT * v3112);
struct StateT * slot_99(struct StateT * v2485);
struct StateT * slot_179(struct StateT * v4008);
struct StateT * slot_219(struct StateT * v1087);
struct StateT * slot_36(struct StateT * v628);
struct StateT * slot_57(struct StateT * v1100);
struct StateT * slot_62(struct StateT * v1265);
struct StateT * slot_22(struct StateT * v409);
struct StateT * slot_139(struct StateT * v3380);
struct StateT * slot_221(struct StateT * v1150);
struct StateT * slot_23(struct StateT * v428);
struct StateT * slot_153(struct StateT * v3602);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_86(struct StateT * v2030);
struct StateT * slot_129(struct StateT * v3220);
struct StateT * slot_158(struct StateT * v3681);
struct StateT * slot_100(struct StateT * v2518);
struct StateT * slot_271(struct StateT * v2810);
struct StateT * slot_127(struct StateT * v3187);
struct StateT * slot_217(struct StateT * v1023);
struct StateT * slot_13(struct StateT * v244);
struct StateT * slot_111(struct StateT * v2901);
struct StateT * slot_109(struct StateT * v2829);
struct StateT * slot_174(struct StateT * v3931);
struct StateT * slot_147(struct StateT * v3501);
struct StateT * slot_42(struct StateT * v742);
struct StateT * slot_224(struct StateT * v1246);
struct StateT * slot_163(struct StateT * v3755);
struct StateT * slot_184(struct StateT * v4083);
struct StateT * slot_204(struct StateT * v4395);
struct StateT * slot_194(struct StateT * v4243);
struct StateT * slot_165(struct StateT * v3786);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v2081);
struct StateT * slot_259(struct StateT * v2397);
struct StateT * slot_117(struct StateT * v3036);
struct StateT * slot_249(struct StateT * v2046);
struct StateT * slot_90(struct StateT * v2170);
struct StateT * slot_11(struct StateT * v206);
struct StateT * slot_12(struct StateT * v225) {
  int v226 = v225->timer;
  int v235 = v226 + 1;
  v225->timer = v235;
  int * v228 = v225->regs;
  int v229 = v228[2];
  int v230 = v228[26];
  int * v231 = v225->mem;
  int v240 = (int)((unsigned int)(v229 + 48) >> 2);
  v231[v240] = v230;
  struct StateT * v233 = slot_13(v225);
  return v233;
}

struct StateT * slot_228(struct StateT * v1375) {
  int v1376 = v1375->timer;
  int v1382 = v1376 + 1;
  v1375->timer = v1382;
  int * v1378 = v1375->regs;
  v1378[7] = 2036477952;
  struct StateT * v1380 = slot_229(v1375);
  return v1380;
}

struct StateT * slot_143(struct StateT * v3439) {
  int v3440 = v3439->timer;
  int v3448 = v3440 + 1;
  v3439->timer = v3448;
  int * v3442 = v3439->regs;
  int v3443 = v3442[16];
  int v3444 = v3442[5];
  int v3452 = v3443 | v3444;
  v3442[16] = v3452;
  struct StateT * v3446 = slot_144(v3439);
  return v3446;
}

struct StateT * slot_120(struct StateT * v3081) {
  int v3082 = v3081->timer;
  int v3090 = v3082 + 1;
  v3081->timer = v3090;
  int * v3084 = v3081->regs;
  int v3085 = v3084[16];
  int v3086 = v3084[6];
  int v3094 = v3085 | v3086;
  v3084[16] = v3094;
  struct StateT * v3088 = slot_121(v3081);
  return v3088;
}

struct StateT * slot_226(struct StateT * v1311) {
  int v1312 = v1311->timer;
  int v1321 = v1312 + 1;
  v1311->timer = v1321;
  int * v1314 = v1311->regs;
  int v1315 = v1314[2];
  int * v1316 = v1311->mem;
  int v1325 = (int)((unsigned int)(v1315 + 24) >> 2);
  int v1317 = v1316[v1325];
  v1314[7] = v1317;
  struct StateT * v1319 = slot_227(v1311);
  return v1319;
}

struct StateT * slot_167(struct StateT * v3816) {
  int v3817 = v3816->timer;
  int v3825 = v3817 + 1;
  v3816->timer = v3825;
  int * v3819 = v3816->regs;
  int v3820 = v3819[27];
  int v3821 = v3819[11];
  int v3829 = v3820 ^ v3821;
  v3819[27] = v3829;
  struct StateT * v3823 = slot_168(v3816);
  return v3823;
}

struct StateT * slot_268(struct StateT * v2703) {
  int v2704 = v2703->timer;
  int v2713 = v2704 + 1;
  v2703->timer = v2713;
  int * v2706 = v2703->regs;
  int v2707 = v2706[2];
  int * v2708 = v2703->mem;
  int v2717 = (int)((unsigned int)(v2707 + 68) >> 2);
  int v2709 = v2708[v2717];
  v2706[21] = v2709;
  struct StateT * v2711 = slot_269(v2703);
  return v2711;
}

struct StateT * slot_152(struct StateT * v3585) {
  int v3586 = v3585->timer;
  int v3594 = v3586 + 1;
  v3585->timer = v3594;
  int * v3588 = v3585->regs;
  int v3589 = v3588[5];
  int v3590 = v3588[20];
  int v3599 = v3589 + v3590;
  v3588[15] = v3599;
  struct StateT * v3592 = slot_153(v3585);
  return v3592;
}

struct StateT * slot_231(struct StateT * v1471) {
  int v1472 = v1471->timer;
  int v1481 = v1472 + 1;
  v1471->timer = v1481;
  int * v1474 = v1471->regs;
  int v1475 = v1474[2];
  int * v1476 = v1471->mem;
  int v1485 = (int)((unsigned int)(v1475 + 32) >> 2);
  int v1477 = v1476[v1485];
  v1474[30] = v1477;
  struct StateT * v1479 = slot_232(v1471);
  return v1479;
}

struct StateT * slot_199(struct StateT * v4320) {
  int v4321 = v4320->timer;
  int v4328 = v4321 + 1;
  v4320->timer = v4328;
  int * v4323 = v4320->regs;
  int v4324 = v4323[15];
  int v4331 = v4324 << 18;
  v4323[15] = v4331;
  struct StateT * v4326 = slot_200(v4320);
  return v4326;
}

struct StateT * slot_252(struct StateT * v2151) {
  int v2152 = v2151->timer;
  int v2161 = v2152 + 1;
  v2151->timer = v2161;
  int * v2154 = v2151->regs;
  int v2155 = v2154[10];
  int v2156 = v2154[5];
  int * v2157 = v2151->mem;
  int v2166 = (int)((unsigned int)(v2155 + 24) >> 2);
  v2157[v2166] = v2156;
  struct StateT * v2159 = slot_253(v2151);
  return v2159;
}

struct StateT * slot_92(struct StateT * v2241) {
  int v2242 = v2241->timer;
  int v2250 = v2242 + 1;
  v2241->timer = v2250;
  int * v2244 = v2241->regs;
  int v2245 = v2244[24];
  int v2246 = v2244[13];
  int v2255 = v2245 + v2246;
  v2244[8] = v2255;
  struct StateT * v2248 = slot_93(v2241);
  return v2248;
}

struct StateT * slot_232(struct StateT * v1506) {
  int v1507 = v1506->timer;
  int v1515 = v1507 + 1;
  v1506->timer = v1515;
  int * v1509 = v1506->regs;
  int v1510 = v1509[16];
  int v1511 = v1509[30];
  int v1519 = v1510 + v1511;
  v1509[16] = v1519;
  struct StateT * v1513 = slot_233(v1506);
  return v1513;
}

struct StateT * slot_269(struct StateT * v2739) {
  int v2740 = v2739->timer;
  int v2749 = v2740 + 1;
  v2739->timer = v2749;
  int * v2742 = v2739->regs;
  int v2743 = v2742[2];
  int * v2744 = v2739->mem;
  int v2753 = (int)((unsigned int)(v2743 + 64) >> 2);
  int v2745 = v2744[v2753];
  v2742[22] = v2745;
  struct StateT * v2747 = slot_270(v2739);
  return v2747;
}

struct StateT * slot_31(struct StateT * v558) {
  int v559 = v558->timer;
  int v566 = v559 + 1;
  v558->timer = v566;
  int * v561 = v558->regs;
  int v562 = v561[13];
  int v570 = v562 + 1134;
  v561[11] = v570;
  struct StateT * v564 = slot_32(v558);
  return v564;
}

struct StateT * slot_236(struct StateT * v1643) {
  int v1644 = v1643->timer;
  int v1652 = v1644 + 1;
  v1643->timer = v1652;
  int * v1646 = v1643->regs;
  int v1647 = v1646[1];
  int v1648 = v1646[30];
  int v1656 = v1647 + v1648;
  v1646[1] = v1656;
  struct StateT * v1650 = slot_237(v1643);
  return v1650;
}

struct StateT * slot_241(struct StateT * v1791) {
  int v1792 = v1791->timer;
  int v1799 = v1792 + 1;
  v1791->timer = v1799;
  int * v1794 = v1791->regs;
  int v1795 = v1794[30];
  int v1802 = v1795 + 1396;
  v1794[30] = v1802;
  struct StateT * v1797 = slot_242(v1791);
  return v1797;
}

struct StateT * slot_160(struct StateT * v3710) {
  int v3711 = v3710->timer;
  int v3719 = v3711 + 1;
  v3710->timer = v3719;
  int * v3713 = v3710->regs;
  int v3714 = v3713[15];
  int v3715 = v3713[9];
  int v3723 = v3714 | v3715;
  v3713[15] = v3723;
  struct StateT * v3717 = slot_161(v3710);
  return v3717;
}

struct StateT * slot_251(struct StateT * v2116) {
  int v2117 = v2116->timer;
  int v2126 = v2117 + 1;
  v2116->timer = v2126;
  int * v2119 = v2116->regs;
  int v2120 = v2119[10];
  int v2121 = v2119[11];
  int * v2122 = v2116->mem;
  int v2131 = (int)((unsigned int)(v2120 + 20) >> 2);
  v2122[v2131] = v2121;
  struct StateT * v2124 = slot_252(v2116);
  return v2124;
}

struct StateT * slot_65(struct StateT * v1361) {
  int v1362 = v1361->timer;
  int v1369 = v1362 + 1;
  v1361->timer = v1369;
  int * v1364 = v1361->regs;
  int v1365 = v1364[8];
  int v1372 = v1365 << 7;
  v1364[8] = v1372;
  struct StateT * v1367 = slot_66(v1361);
  return v1367;
}

struct StateT * slot_10(struct StateT * v187) {
  int v188 = v187->timer;
  int v197 = v188 + 1;
  v187->timer = v197;
  int * v190 = v187->regs;
  int v191 = v190[2];
  int v192 = v190[24];
  int * v193 = v187->mem;
  int v202 = (int)((unsigned int)(v191 + 56) >> 2);
  v193[v202] = v192;
  struct StateT * v195 = slot_11(v187);
  return v195;
}

struct StateT * slot_150(struct StateT * v3551) {
  int v3552 = v3551->timer;
  int v3560 = v3552 + 1;
  v3551->timer = v3560;
  int * v3554 = v3551->regs;
  int v3555 = v3554[9];
  int v3556 = v3554[6];
  int v3565 = v3555 ^ v3556;
  v3554[16] = v3565;
  struct StateT * v3558 = slot_151(v3551);
  return v3558;
}

struct StateT * slot_74(struct StateT * v1659) {
  int v1660 = v1659->timer;
  int v1668 = v1660 + 1;
  v1659->timer = v1668;
  int * v1662 = v1659->regs;
  int v1663 = v1662[14];
  int v1664 = v1662[22];
  int v1673 = v1663 + v1664;
  v1662[18] = v1673;
  struct StateT * v1666 = slot_75(v1659);
  return v1666;
}

struct StateT * slot_262(struct StateT * v2499) {
  int v2500 = v2499->timer;
  int v2509 = v2500 + 1;
  v2499->timer = v2509;
  int * v2502 = v2499->regs;
  int v2503 = v2502[2];
  int * v2504 = v2499->mem;
  int v2513 = (int)((unsigned int)(v2503 + 92) >> 2);
  int v2505 = v2504[v2513];
  v2502[1] = v2505;
  struct StateT * v2507 = slot_263(v2499);
  return v2507;
}

struct StateT * slot_107(struct StateT * v2758) {
  int v2759 = v2758->timer;
  int v2767 = v2759 + 1;
  v2758->timer = v2767;
  int * v2761 = v2758->regs;
  int v2762 = v2761[16];
  int v2763 = v2761[15];
  int v2772 = v2762 ^ v2763;
  v2761[9] = v2772;
  struct StateT * v2765 = slot_108(v2758);
  return v2765;
}

struct StateT * slot_136(struct StateT * v3335) {
  int v3336 = v3335->timer;
  int v3343 = v3336 + 1;
  v3335->timer = v3343;
  int * v3338 = v3335->regs;
  int v3339 = v3338[15];
  int v3346 = v3339 << 7;
  v3338[15] = v3346;
  struct StateT * v3341 = slot_137(v3335);
  return v3341;
}

struct StateT * slot_84(struct StateT * v1963) {
  int v1964 = v1963->timer;
  int v1971 = v1964 + 1;
  v1963->timer = v1971;
  int * v1966 = v1963->regs;
  int v1967 = v1966[18];
  int v1975 = (int)((unsigned int)v1967 >> 23);
  v1966[20] = v1975;
  struct StateT * v1969 = slot_85(v1963);
  return v1969;
}

struct StateT * slot_28(struct StateT * v517) {
  int v518 = v517->timer;
  int v524 = v518 + 1;
  v517->timer = v524;
  int * v520 = v517->regs;
  v520[13] = 857759744;
  struct StateT * v522 = slot_29(v517);
  return v522;
}

struct StateT * slot_155(struct StateT * v3636) {
  int v3637 = v3636->timer;
  int v3644 = v3637 + 1;
  v3636->timer = v3644;
  int * v3639 = v3636->regs;
  int v3640 = v3639[11];
  int v3648 = (int)((unsigned int)v3640 >> 23);
  v3639[9] = v3648;
  struct StateT * v3642 = slot_156(v3636);
  return v3642;
}

struct StateT * slot_177(struct StateT * v3977) {
  int v3978 = v3977->timer;
  int v3986 = v3978 + 1;
  v3977->timer = v3986;
  int * v3980 = v3977->regs;
  int v3981 = v3980[11];
  int v3982 = v3980[9];
  int v3990 = v3981 | v3982;
  v3980[11] = v3990;
  struct StateT * v3984 = slot_178(v3977);
  return v3984;
}

struct StateT * slot_229(struct StateT * v1404) {
  int v1405 = v1404->timer;
  int v1414 = v1405 + 1;
  v1404->timer = v1414;
  int * v1407 = v1404->regs;
  int v1408 = v1407[2];
  int * v1409 = v1404->mem;
  int v1418 = (int)((unsigned int)(v1408 + 28) >> 2);
  int v1410 = v1409[v1418];
  v1407[30] = v1410;
  struct StateT * v1412 = slot_230(v1404);
  return v1412;
}

struct StateT * slot_17(struct StateT * v314) {
  int v315 = v314->timer;
  int v324 = v315 + 1;
  v314->timer = v324;
  int * v317 = v314->regs;
  int v318 = v317[12];
  int * v319 = v314->mem;
  int v328 = (int)((unsigned int)(v318 + 8) >> 2);
  int v320 = v319[v328];
  v317[7] = v320;
  struct StateT * v322 = slot_18(v314);
  return v322;
}

struct StateT * slot_181(struct StateT * v4038) {
  int v4039 = v4038->timer;
  int v4046 = v4039 + 1;
  v4038->timer = v4046;
  int * v4041 = v4038->regs;
  int v4042 = v4041[6];
  int v4050 = (int)((unsigned int)v4042 >> 19);
  v4041[9] = v4050;
  struct StateT * v4044 = slot_182(v4038);
  return v4044;
}

struct StateT * slot_197(struct StateT * v4289) {
  int v4290 = v4289->timer;
  int v4298 = v4290 + 1;
  v4289->timer = v4298;
  int * v4292 = v4289->regs;
  int v4293 = v4292[11];
  int v4294 = v4292[9];
  int v4302 = v4293 | v4294;
  v4292[11] = v4302;
  struct StateT * v4296 = slot_198(v4289);
  return v4296;
}

struct StateT * slot_207(struct StateT * v4440) {
  int v4441 = v4440->timer;
  int v4449 = v4441 + 1;
  v4440->timer = v4449;
  int * v4443 = v4440->regs;
  int v4444 = v4443[21];
  int v4445 = v4443[11];
  int v4453 = v4444 ^ v4445;
  v4443[21] = v4453;
  struct StateT * v4447 = slot_208(v4440);
  return v4447;
}

struct StateT * slot_156(struct StateT * v3651) {
  int v3652 = v3651->timer;
  int v3659 = v3652 + 1;
  v3651->timer = v3659;
  int * v3654 = v3651->regs;
  int v3655 = v3654[11];
  int v3662 = v3655 << 9;
  v3654[11] = v3662;
  struct StateT * v3657 = slot_157(v3651);
  return v3657;
}

struct StateT * slot_154(struct StateT * v3619) {
  int v3620 = v3619->timer;
  int v3628 = v3620 + 1;
  v3619->timer = v3628;
  int * v3622 = v3619->regs;
  int v3623 = v3622[16];
  int v3624 = v3622[22];
  int v3633 = v3623 + v3624;
  v3622[8] = v3633;
  struct StateT * v3626 = slot_155(v3619);
  return v3626;
}

struct StateT * slot_68(struct StateT * v1455) {
  int v1456 = v1455->timer;
  int v1464 = v1456 + 1;
  v1455->timer = v1464;
  int * v1458 = v1455->regs;
  int v1459 = v1458[13];
  int v1460 = v1458[9];
  int v1468 = v1459 ^ v1460;
  v1458[13] = v1468;
  struct StateT * v1462 = slot_69(v1455);
  return v1462;
}

struct StateT * slot_260(struct StateT * v2432) {
  int v2433 = v2432->timer;
  int v2442 = v2433 + 1;
  v2432->timer = v2442;
  int * v2435 = v2432->regs;
  int v2436 = v2435[10];
  int v2437 = v2435[1];
  int * v2438 = v2432->mem;
  int v2447 = (int)((unsigned int)(v2436 + 56) >> 2);
  v2438[v2447] = v2437;
  struct StateT * v2440 = slot_261(v2432);
  return v2440;
}

struct StateT * slot_105(struct StateT * v2689) {
  int v2690 = v2689->timer;
  int v2697 = v2690 + 1;
  v2689->timer = v2697;
  int * v2692 = v2689->regs;
  int v2693 = v2692[18];
  int v2700 = v2693 << 13;
  v2692[18] = v2700;
  struct StateT * v2695 = slot_106(v2689);
  return v2695;
}

struct StateT * slot_27(struct StateT * v504) {
  int v505 = v504->timer;
  int v511 = v505 + 1;
  v504->timer = v511;
  int * v507 = v504->regs;
  v507[12] = 1634762752;
  struct StateT * v509 = slot_28(v504);
  return v509;
}

struct StateT * slot_164(struct StateT * v3771) {
  int v3772 = v3771->timer;
  int v3779 = v3772 + 1;
  v3771->timer = v3779;
  int * v3774 = v3771->regs;
  int v3775 = v3774[8];
  int v3783 = (int)((unsigned int)v3775 >> 23);
  v3774[9] = v3783;
  struct StateT * v3777 = slot_165(v3771);
  return v3777;
}

struct StateT * slot_15(struct StateT * v276) {
  int v277 = v276->timer;
  int v286 = v277 + 1;
  v276->timer = v286;
  int * v279 = v276->regs;
  int v280 = v279[12];
  int * v281 = v276->mem;
  int v290 = (int)((unsigned int)v280 >> 2);
  int v282 = v281[v290];
  v279[29] = v282;
  struct StateT * v284 = slot_16(v276);
  return v284;
}

struct StateT * slot_133(struct StateT * v3286) {
  int v3287 = v3286->timer;
  int v3295 = v3287 + 1;
  v3286->timer = v3295;
  int * v3289 = v3286->regs;
  int v3290 = v3289[19];
  int v3291 = v3289[13];
  int v3300 = v3290 + v3291;
  v3289[16] = v3300;
  struct StateT * v3293 = slot_134(v3286);
  return v3293;
}

struct StateT * slot_56(struct StateT * v1073) {
  int v1074 = v1073->timer;
  int v1081 = v1074 + 1;
  v1073->timer = v1081;
  int * v1076 = v1073->regs;
  int v1077 = v1076[15];
  int v1084 = v1077 << 7;
  v1076[15] = v1084;
  struct StateT * v1079 = slot_57(v1073);
  return v1079;
}

struct StateT * slot_244(struct StateT * v1882) {
  int v1883 = v1882->timer;
  int v1891 = v1883 + 1;
  v1882->timer = v1891;
  int * v1885 = v1882->regs;
  int v1886 = v1885[19];
  int v1887 = v1885[7];
  int v1895 = v1886 + v1887;
  v1885[7] = v1895;
  struct StateT * v1889 = slot_245(v1882);
  return v1889;
}

struct StateT * slot_222(struct StateT * v1180) {
  int v1181 = v1180->timer;
  int v1190 = v1181 + 1;
  v1180->timer = v1190;
  int * v1183 = v1180->regs;
  int v1184 = v1183[2];
  int * v1185 = v1180->mem;
  int v1194 = (int)((unsigned int)(v1184 + 16) >> 2);
  int v1186 = v1185[v1194];
  v1183[7] = v1186;
  struct StateT * v1188 = slot_223(v1180);
  return v1188;
}

struct StateT * slot_34(struct StateT * v601) {
  int v602 = v601->timer;
  int v609 = v602 + 1;
  v601->timer = v609;
  int * v604 = v601->regs;
  int v605 = v604[22];
  int v612 = v605 + 1396;
  v604[22] = v612;
  struct StateT * v607 = slot_35(v601);
  return v607;
}

struct StateT * slot_171(struct StateT * v3880) {
  int v3881 = v3880->timer;
  int v3889 = v3881 + 1;
  v3880->timer = v3889;
  int * v3883 = v3880->regs;
  int v3884 = v3883[27];
  int v3885 = v3883[23];
  int v3894 = v3884 + v3885;
  v3883[11] = v3894;
  struct StateT * v3887 = slot_172(v3880);
  return v3887;
}

struct StateT * slot_162(struct StateT * v3741) {
  int v3742 = v3741->timer;
  int v3749 = v3742 + 1;
  v3741->timer = v3749;
  int * v3744 = v3741->regs;
  int v3745 = v3744[6];
  int v3752 = v3745 << 9;
  v3744[6] = v3752;
  struct StateT * v3747 = slot_163(v3741);
  return v3747;
}

struct StateT * slot_21(struct StateT * v390) {
  int v391 = v390->timer;
  int v400 = v391 + 1;
  v390->timer = v400;
  int * v393 = v390->regs;
  int v394 = v393[12];
  int * v395 = v390->mem;
  int v404 = (int)((unsigned int)(v394 + 24) >> 2);
  int v396 = v395[v404];
  v393[24] = v396;
  struct StateT * v398 = slot_22(v390);
  return v398;
}

struct StateT * slot_239(struct StateT * v1732) {
  int v1733 = v1732->timer;
  int v1740 = v1733 + 1;
  v1732->timer = v1740;
  int * v1735 = v1732->regs;
  int v1736 = v1735[6];
  int v1743 = v1736 + 1134;
  v1735[6] = v1743;
  struct StateT * v1738 = slot_240(v1732);
  return v1738;
}

struct StateT * slot_118(struct StateT * v3052) {
  int v3053 = v3052->timer;
  int v3060 = v3053 + 1;
  v3052->timer = v3060;
  int * v3055 = v3052->regs;
  int v3056 = v3055[16];
  int v3064 = (int)((unsigned int)v3056 >> 14);
  v3055[6] = v3064;
  struct StateT * v3058 = slot_119(v3052);
  return v3058;
}

struct StateT * slot_121(struct StateT * v3097) {
  int v3098 = v3097->timer;
  int v3105 = v3098 + 1;
  v3097->timer = v3105;
  int * v3100 = v3097->regs;
  int v3101 = v3100[17];
  int v3109 = (int)((unsigned int)v3101 >> 14);
  v3100[6] = v3109;
  struct StateT * v3103 = slot_122(v3097);
  return v3103;
}

struct StateT * slot_144(struct StateT * v3455) {
  int v3456 = v3455->timer;
  int v3463 = v3456 + 1;
  v3455->timer = v3463;
  int * v3458 = v3455->regs;
  int v3459 = v3458[17];
  int v3467 = (int)((unsigned int)v3459 >> 25);
  v3458[5] = v3467;
  struct StateT * v3461 = slot_145(v3455);
  return v3461;
}

struct StateT * slot_267(struct StateT * v2670) {
  int v2671 = v2670->timer;
  int v2680 = v2671 + 1;
  v2670->timer = v2680;
  int * v2673 = v2670->regs;
  int v2674 = v2673[2];
  int * v2675 = v2670->mem;
  int v2684 = (int)((unsigned int)(v2674 + 72) >> 2);
  int v2676 = v2675[v2684];
  v2673[20] = v2676;
  struct StateT * v2678 = slot_268(v2670);
  return v2678;
}

struct StateT * slot_201(struct StateT * v4350) {
  int v4351 = v4350->timer;
  int v4358 = v4351 + 1;
  v4350->timer = v4358;
  int * v4353 = v4350->regs;
  int v4354 = v4353[6];
  int v4362 = (int)((unsigned int)v4354 >> 14);
  v4353[9] = v4362;
  struct StateT * v4356 = slot_202(v4350);
  return v4356;
}

struct StateT * slot_94(struct StateT * v2313) {
  int v2314 = v2313->timer;
  int v2322 = v2314 + 1;
  v2313->timer = v2322;
  int * v2316 = v2313->regs;
  int v2317 = v2316[25];
  int v2318 = v2316[14];
  int v2327 = v2317 + v2318;
  v2316[18] = v2327;
  struct StateT * v2320 = slot_95(v2313);
  return v2320;
}

struct StateT * slot_63(struct StateT * v1295) {
  int v1296 = v1295->timer;
  int v1304 = v1296 + 1;
  v1295->timer = v1304;
  int * v1298 = v1295->regs;
  int v1299 = v1298[18];
  int v1300 = v1298[20];
  int v1308 = v1299 | v1300;
  v1298[18] = v1308;
  struct StateT * v1302 = slot_64(v1295);
  return v1302;
}

struct StateT * slot_146(struct StateT * v3484) {
  int v3485 = v3484->timer;
  int v3493 = v3485 + 1;
  v3484->timer = v3493;
  int * v3487 = v3484->regs;
  int v3488 = v3487[17];
  int v3489 = v3487[5];
  int v3498 = v3488 | v3489;
  v3487[6] = v3498;
  struct StateT * v3491 = slot_147(v3484);
  return v3491;
}

struct StateT * slot_24(struct StateT * v447) {
  int v448 = v447->timer;
  int v457 = v448 + 1;
  v447->timer = v457;
  int * v450 = v447->regs;
  int v451 = v450[11];
  int * v452 = v447->mem;
  int v461 = (int)((unsigned int)(v451 + 4) >> 2);
  int v453 = v452[v461];
  v450[25] = v453;
  struct StateT * v455 = slot_25(v447);
  return v455;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -96;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_195(struct StateT * v4260) {
  int v4261 = v4260->timer;
  int v4268 = v4261 + 1;
  v4260->timer = v4268;
  int * v4263 = v4260->regs;
  int v4264 = v4263[11];
  int v4272 = (int)((unsigned int)v4264 >> 14);
  v4263[9] = v4272;
  struct StateT * v4266 = slot_196(v4260);
  return v4266;
}

struct StateT * slot_125(struct StateT * v3157) {
  int v3158 = v3157->timer;
  int v3165 = v3158 + 1;
  v3157->timer = v3165;
  int * v3160 = v3157->regs;
  int v3161 = v3160[5];
  int v3168 = v3161 << 18;
  v3160[5] = v3168;
  struct StateT * v3163 = slot_126(v3157);
  return v3163;
}

struct StateT * slot_254(struct StateT * v2222) {
  int v2223 = v2222->timer;
  int v2232 = v2223 + 1;
  v2222->timer = v2232;
  int * v2225 = v2222->regs;
  int v2226 = v2225[10];
  int v2227 = v2225[26];
  int * v2228 = v2222->mem;
  int v2237 = (int)((unsigned int)(v2226 + 32) >> 2);
  v2228[v2237] = v2227;
  struct StateT * v2230 = slot_255(v2222);
  return v2230;
}

struct StateT * slot_148(struct StateT * v3517) {
  int v3518 = v3517->timer;
  int v3526 = v3518 + 1;
  v3517->timer = v3526;
  int * v3520 = v3517->regs;
  int v3521 = v3520[18];
  int v3522 = v3520[11];
  int v3531 = v3521 ^ v3522;
  v3520[5] = v3531;
  struct StateT * v3524 = slot_149(v3517);
  return v3524;
}

struct StateT * slot_126(struct StateT * v3171) {
  int v3172 = v3171->timer;
  int v3180 = v3172 + 1;
  v3171->timer = v3180;
  int * v3174 = v3171->regs;
  int v3175 = v3174[5];
  int v3176 = v3174[6];
  int v3184 = v3175 | v3176;
  v3174[5] = v3184;
  struct StateT * v3178 = slot_127(v3171);
  return v3178;
}

struct StateT * slot_223(struct StateT * v1215) {
  int v1216 = v1215->timer;
  int v1224 = v1216 + 1;
  v1215->timer = v1224;
  int * v1218 = v1215->regs;
  int v1219 = v1218[25];
  int v1220 = v1218[7];
  int v1228 = v1219 + v1220;
  v1218[25] = v1228;
  struct StateT * v1222 = slot_224(v1215);
  return v1222;
}

struct StateT * slot_79(struct StateT * v1805) {
  int v1806 = v1805->timer;
  int v1813 = v1806 + 1;
  v1805->timer = v1813;
  int * v1808 = v1805->regs;
  int v1809 = v1808[8];
  int v1816 = v1809 << 9;
  v1808[8] = v1816;
  struct StateT * v1811 = slot_80(v1805);
  return v1811;
}

struct StateT * slot_237(struct StateT * v1676) {
  int v1677 = v1676->timer;
  int v1683 = v1677 + 1;
  v1676->timer = v1683;
  int * v1679 = v1676->regs;
  v1679[30] = 1797283840;
  struct StateT * v1681 = slot_238(v1676);
  return v1681;
}

struct StateT * slot_41(struct StateT * v723) {
  int v724 = v723->timer;
  int v733 = v724 + 1;
  v723->timer = v733;
  int * v726 = v723->regs;
  int v727 = v726[2];
  int v728 = v726[16];
  int * v729 = v723->mem;
  int v738 = (int)((unsigned int)(v727 + 32) >> 2);
  v729[v738] = v728;
  struct StateT * v731 = slot_42(v723);
  return v731;
}

struct StateT * slot_39(struct StateT * v685) {
  int v686 = v685->timer;
  int v695 = v686 + 1;
  v685->timer = v695;
  int * v688 = v685->regs;
  int v689 = v688[2];
  int v690 = v688[1];
  int * v691 = v685->mem;
  int v700 = (int)((unsigned int)(v689 + 40) >> 2);
  v691[v700] = v690;
  struct StateT * v693 = slot_40(v685);
  return v693;
}

struct StateT * slot_142(struct StateT * v3425) {
  int v3426 = v3425->timer;
  int v3433 = v3426 + 1;
  v3425->timer = v3433;
  int * v3428 = v3425->regs;
  int v3429 = v3428[16];
  int v3436 = v3429 << 7;
  v3428[16] = v3436;
  struct StateT * v3431 = slot_143(v3425);
  return v3431;
}

struct StateT * slot_60(struct StateT * v1199) {
  int v1200 = v1199->timer;
  int v1208 = v1200 + 1;
  v1199->timer = v1208;
  int * v1202 = v1199->regs;
  int v1203 = v1202[20];
  int v1204 = v1202[9];
  int v1212 = v1203 | v1204;
  v1202[9] = v1212;
  struct StateT * v1206 = slot_61(v1199);
  return v1206;
}

struct StateT * slot_238(struct StateT * v1704) {
  int v1705 = v1704->timer;
  int v1712 = v1705 + 1;
  v1704->timer = v1712;
  int * v1707 = v1704->regs;
  int v1708 = v1707[15];
  int v1715 = v1708 + -1947;
  v1707[15] = v1715;
  struct StateT * v1710 = slot_239(v1704);
  return v1710;
}

struct StateT * slot_112(struct StateT * v2937) {
  int v2938 = v2937->timer;
  int v2946 = v2938 + 1;
  v2937->timer = v2946;
  int * v2940 = v2937->regs;
  int v2941 = v2940[23];
  int v2942 = v2940[24];
  int v2951 = v2941 + v2942;
  v2940[16] = v2951;
  struct StateT * v2944 = slot_113(v2937);
  return v2944;
}

struct StateT * slot_256(struct StateT * v2294) {
  int v2295 = v2294->timer;
  int v2304 = v2295 + 1;
  v2294->timer = v2304;
  int * v2297 = v2294->regs;
  int v2298 = v2297[10];
  int v2299 = v2297[7];
  int * v2300 = v2294->mem;
  int v2309 = (int)((unsigned int)(v2298 + 40) >> 2);
  v2300[v2309] = v2299;
  struct StateT * v2302 = slot_257(v2294);
  return v2302;
}

struct StateT * slot_272(struct StateT * v2846) {
  int v2847 = v2846->timer;
  int v2856 = v2847 + 1;
  v2846->timer = v2856;
  int * v2849 = v2846->regs;
  int v2850 = v2849[2];
  int * v2851 = v2846->mem;
  int v2860 = (int)((unsigned int)(v2850 + 52) >> 2);
  int v2852 = v2851[v2860];
  v2849[25] = v2852;
  struct StateT * v2854 = slot_273(v2846);
  return v2854;
}

struct StateT * slot_47(struct StateT * v825) {
  int v826 = v825->timer;
  int v833 = v826 + 1;
  v825->timer = v833;
  int * v828 = v825->regs;
  int v829 = v828[29];
  v828[23] = v829;
  struct StateT * v831 = slot_48(v825);
  return v831;
}

struct StateT * slot_214(struct StateT * v927) {
  int v928 = v927->timer;
  int v936 = v928 + 1;
  v927->timer = v936;
  int * v930 = v927->regs;
  int v931 = v930[27];
  int v932 = v930[28];
  int v940 = v931 + v932;
  v930[28] = v940;
  struct StateT * v934 = slot_215(v927);
  return v934;
}

struct StateT * slot_29(struct StateT * v530) {
  int v531 = v530->timer;
  int v537 = v531 + 1;
  v530->timer = v537;
  int * v533 = v530->regs;
  v533[14] = 2036477952;
  struct StateT * v535 = slot_30(v530);
  return v535;
}

struct StateT * slot_16(struct StateT * v295) {
  int v296 = v295->timer;
  int v305 = v296 + 1;
  v295->timer = v305;
  int * v298 = v295->regs;
  int v299 = v298[12];
  int * v300 = v295->mem;
  int v309 = (int)((unsigned int)(v299 + 4) >> 2);
  int v301 = v300[v309];
  v298[28] = v301;
  struct StateT * v303 = slot_17(v295);
  return v303;
}

struct StateT * slot_245(struct StateT * v1912) {
  int v1913 = v1912->timer;
  int v1921 = v1913 + 1;
  v1912->timer = v1921;
  int * v1915 = v1912->regs;
  int v1916 = v1915[22];
  int v1917 = v1915[30];
  int v1925 = v1916 + v1917;
  v1915[30] = v1925;
  struct StateT * v1919 = slot_246(v1912);
  return v1919;
}

struct StateT * slot_113(struct StateT * v2968) {
  int v2969 = v2968->timer;
  int v2977 = v2969 + 1;
  v2968->timer = v2977;
  int * v2971 = v2968->regs;
  int v2972 = v2971[18];
  int v2973 = v2971[27];
  int v2982 = v2972 + v2973;
  v2971[17] = v2982;
  struct StateT * v2975 = slot_114(v2968);
  return v2975;
}

struct StateT * slot_151(struct StateT * v3568) {
  int v3569 = v3568->timer;
  int v3577 = v3569 + 1;
  v3568->timer = v3577;
  int * v3571 = v3568->regs;
  int v3572 = v3571[23];
  int v3573 = v3571[21];
  int v3582 = v3572 + v3573;
  v3571[11] = v3582;
  struct StateT * v3575 = slot_152(v3568);
  return v3575;
}

struct StateT * slot_7(struct StateT * v130) {
  int v131 = v130->timer;
  int v140 = v131 + 1;
  v130->timer = v140;
  int * v133 = v130->regs;
  int v134 = v133[2];
  int v135 = v133[21];
  int * v136 = v130->mem;
  int v145 = (int)((unsigned int)(v134 + 68) >> 2);
  v136[v145] = v135;
  struct StateT * v138 = slot_8(v130);
  return v138;
}

struct StateT * slot_124(struct StateT * v3142) {
  int v3143 = v3142->timer;
  int v3150 = v3143 + 1;
  v3142->timer = v3150;
  int * v3145 = v3142->regs;
  int v3146 = v3145[5];
  int v3154 = (int)((unsigned int)v3146 >> 14);
  v3145[6] = v3154;
  struct StateT * v3148 = slot_125(v3142);
  return v3148;
}

struct StateT * slot_191(struct StateT * v4192) {
  int v4193 = v4192->timer;
  int v4201 = v4193 + 1;
  v4192->timer = v4201;
  int * v4195 = v4192->regs;
  int v4196 = v4195[14];
  int v4197 = v4195[27];
  int v4206 = v4196 + v4197;
  v4195[11] = v4206;
  struct StateT * v4199 = slot_192(v4192);
  return v4199;
}

struct StateT * slot_103(struct StateT * v2620) {
  int v2621 = v2620->timer;
  int v2629 = v2621 + 1;
  v2620->timer = v2629;
  int * v2623 = v2620->regs;
  int v2624 = v2623[9];
  int v2625 = v2623[20];
  int v2633 = v2624 | v2625;
  v2623[20] = v2633;
  struct StateT * v2627 = slot_104(v2620);
  return v2627;
}

struct StateT * slot_128(struct StateT * v3203) {
  int v3204 = v3203->timer;
  int v3212 = v3204 + 1;
  v3203->timer = v3212;
  int * v3206 = v3203->regs;
  int v3207 = v3206[11];
  int v3208 = v3206[16];
  int v3217 = v3207 ^ v3208;
  v3206[20] = v3217;
  struct StateT * v3210 = slot_129(v3203);
  return v3210;
}

struct StateT * slot_19(struct StateT * v352) {
  int v353 = v352->timer;
  int v362 = v353 + 1;
  v352->timer = v362;
  int * v355 = v352->regs;
  int v356 = v355[12];
  int * v357 = v352->mem;
  int v366 = (int)((unsigned int)(v356 + 16) >> 2);
  int v358 = v357[v366];
  v355[17] = v358;
  struct StateT * v360 = slot_20(v352);
  return v360;
}

struct StateT * slot_87(struct StateT * v2065) {
  int v2066 = v2065->timer;
  int v2074 = v2066 + 1;
  v2065->timer = v2074;
  int * v2068 = v2065->regs;
  int v2069 = v2068[26];
  int v2070 = v2068[15];
  int v2078 = v2069 ^ v2070;
  v2068[26] = v2078;
  struct StateT * v2072 = slot_88(v2065);
  return v2072;
}

struct StateT * slot_67(struct StateT * v1423) {
  int v1424 = v1423->timer;
  int v1432 = v1424 + 1;
  v1423->timer = v1432;
  int * v1426 = v1423->regs;
  int v1427 = v1426[12];
  int v1428 = v1426[15];
  int v1436 = v1427 ^ v1428;
  v1426[12] = v1436;
  struct StateT * v1430 = slot_68(v1423);
  return v1430;
}

struct StateT * slot_81(struct StateT * v1867) {
  int v1868 = v1867->timer;
  int v1875 = v1868 + 1;
  v1867->timer = v1875;
  int * v1870 = v1867->regs;
  int v1871 = v1870[9];
  int v1879 = (int)((unsigned int)v1871 >> 23);
  v1870[20] = v1879;
  struct StateT * v1873 = slot_82(v1867);
  return v1873;
}

struct StateT * slot_95(struct StateT * v2349) {
  int v2350 = v2349->timer;
  int v2357 = v2350 + 1;
  v2349->timer = v2357;
  int * v2352 = v2349->regs;
  int v2353 = v2352[15];
  int v2361 = (int)((unsigned int)v2353 >> 19);
  v2352[20] = v2361;
  struct StateT * v2355 = slot_96(v2349);
  return v2355;
}

struct StateT * slot_115(struct StateT * v3007) {
  int v3008 = v3007->timer;
  int v3015 = v3008 + 1;
  v3007->timer = v3015;
  int * v3010 = v3007->regs;
  int v3011 = v3010[15];
  int v3019 = (int)((unsigned int)v3011 >> 14);
  v3010[6] = v3019;
  struct StateT * v3013 = slot_116(v3007);
  return v3013;
}

struct StateT * slot_78(struct StateT * v1776) {
  int v1777 = v1776->timer;
  int v1784 = v1777 + 1;
  v1776->timer = v1784;
  int * v1779 = v1776->regs;
  int v1780 = v1779[8];
  int v1788 = (int)((unsigned int)v1780 >> 23);
  v1779[20] = v1788;
  struct StateT * v1782 = slot_79(v1776);
  return v1782;
}

struct StateT * slot_32(struct StateT * v573) {
  int v574 = v573->timer;
  int v581 = v574 + 1;
  v573->timer = v581;
  int * v576 = v573->regs;
  int v577 = v576[14];
  int v585 = v577 + -718;
  v576[19] = v585;
  struct StateT * v579 = slot_33(v573);
  return v579;
}

struct StateT * slot_205(struct StateT * v4410) {
  int v4411 = v4410->timer;
  int v4418 = v4411 + 1;
  v4410->timer = v4418;
  int * v4413 = v4410->regs;
  int v4414 = v4413[8];
  int v4421 = v4414 << 18;
  v4413[8] = v4421;
  struct StateT * v4416 = slot_206(v4410);
  return v4416;
}

struct StateT * slot_193(struct StateT * v4226) {
  int v4227 = v4226->timer;
  int v4235 = v4227 + 1;
  v4226->timer = v4235;
  int * v4229 = v4226->regs;
  int v4230 = v4229[13];
  int v4231 = v4229[26];
  int v4240 = v4230 + v4231;
  v4229[6] = v4240;
  struct StateT * v4233 = slot_194(v4226);
  return v4233;
}

struct StateT * slot_233(struct StateT * v1538) {
  int v1539 = v1538->timer;
  int v1548 = v1539 + 1;
  v1538->timer = v1548;
  int * v1541 = v1538->regs;
  int v1542 = v1541[2];
  int * v1543 = v1538->mem;
  int v1552 = (int)((unsigned int)(v1542 + 36) >> 2);
  int v1544 = v1543[v1552];
  v1541[30] = v1544;
  struct StateT * v1546 = slot_234(v1538);
  return v1546;
}

struct StateT * slot_176(struct StateT * v3963) {
  int v3964 = v3963->timer;
  int v3971 = v3964 + 1;
  v3963->timer = v3971;
  int * v3966 = v3963->regs;
  int v3967 = v3966[11];
  int v3974 = v3967 << 13;
  v3966[11] = v3974;
  struct StateT * v3969 = slot_177(v3963);
  return v3969;
}

struct StateT * slot_189(struct StateT * v4160) {
  int v4161 = v4160->timer;
  int v4169 = v4161 + 1;
  v4160->timer = v4169;
  int * v4163 = v4160->regs;
  int v4164 = v4163[13];
  int v4165 = v4163[6];
  int v4173 = v4164 ^ v4165;
  v4163[13] = v4173;
  struct StateT * v4167 = slot_190(v4160);
  return v4167;
}

struct StateT * slot_33(struct StateT * v588) {
  int v589 = v588->timer;
  int v595 = v589 + 1;
  v588->timer = v595;
  int * v591 = v588->regs;
  v591[22] = 1797283840;
  struct StateT * v593 = slot_34(v588);
  return v593;
}

struct StateT * slot_35(struct StateT * v615) {
  int v616 = v615->timer;
  int v622 = v616 + 1;
  v615->timer = v622;
  int * v618 = v615->regs;
  v618[31] = 9;
  struct StateT * v620 = slot_36(v615);
  return v620;
}

struct StateT * slot_258(struct StateT * v2364) {
  int v2365 = v2364->timer;
  int v2374 = v2365 + 1;
  v2364->timer = v2374;
  int * v2367 = v2364->regs;
  int v2368 = v2367[10];
  int v2369 = v2367[16];
  int * v2370 = v2364->mem;
  int v2379 = (int)((unsigned int)(v2368 + 48) >> 2);
  v2370[v2379] = v2369;
  struct StateT * v2372 = slot_259(v2364);
  return v2372;
}

struct StateT * slot_246(struct StateT * v1944) {
  int v1945 = v1944->timer;
  int v1954 = v1945 + 1;
  v1944->timer = v1954;
  int * v1947 = v1944->regs;
  int v1948 = v1947[10];
  int v1949 = v1947[15];
  int * v1950 = v1944->mem;
  int v1959 = (int)((unsigned int)v1948 >> 2);
  v1950[v1959] = v1949;
  struct StateT * v1952 = slot_247(v1944);
  return v1952;
}

struct StateT * slot_210(struct StateT * v4489) {
  int v4490 = v4489->timer;
  int v4498 = v4490 + 1;
  v4489->timer = v4498;
  int * v4492 = v4489->regs;
  int v4493 = v4492[22];
  int v4494 = v4492[8];
  int v4502 = v4493 ^ v4494;
  v4492[22] = v4502;
  struct StateT * v4496 = slot_211(v4489);
  return v4496;
}

struct StateT * slot_166(struct StateT * v3800) {
  int v3801 = v3800->timer;
  int v3809 = v3801 + 1;
  v3800->timer = v3809;
  int * v3803 = v3800->regs;
  int v3804 = v3803[8];
  int v3805 = v3803[9];
  int v3813 = v3804 | v3805;
  v3803[8] = v3813;
  struct StateT * v3807 = slot_167(v3800);
  return v3807;
}

struct StateT * slot_51(struct StateT * v910) {
  int v911 = v910->timer;
  int v919 = v911 + 1;
  v910->timer = v919;
  int * v913 = v910->regs;
  int v914 = v913[21];
  int v915 = v913[16];
  int v924 = v914 + v915;
  v913[15] = v924;
  struct StateT * v917 = slot_52(v910);
  return v917;
}

struct StateT * slot_52(struct StateT * v943) {
  int v944 = v943->timer;
  int v952 = v944 + 1;
  v943->timer = v952;
  int * v946 = v943->regs;
  int v947 = v946[11];
  int v948 = v946[23];
  int v957 = v947 + v948;
  v946[20] = v957;
  struct StateT * v950 = slot_53(v943);
  return v950;
}

struct StateT * slot_83(struct StateT * v1928) {
  int v1929 = v1928->timer;
  int v1937 = v1929 + 1;
  v1928->timer = v1937;
  int * v1931 = v1928->regs;
  int v1932 = v1931[9];
  int v1933 = v1931[20];
  int v1941 = v1932 | v1933;
  v1931[9] = v1941;
  struct StateT * v1935 = slot_84(v1928);
  return v1935;
}

struct StateT * slot_25(struct StateT * v466) {
  int v467 = v466->timer;
  int v476 = v467 + 1;
  v466->timer = v476;
  int * v469 = v466->regs;
  int v470 = v469[11];
  int * v471 = v466->mem;
  int v480 = (int)((unsigned int)(v470 + 8) >> 2);
  int v472 = v471[v480];
  v469[26] = v472;
  struct StateT * v474 = slot_26(v466);
  return v474;
}

struct StateT * slot_209(struct StateT * v4473) {
  int v4474 = v4473->timer;
  int v4482 = v4474 + 1;
  v4473->timer = v4482;
  int * v4476 = v4473->regs;
  int v4477 = v4476[19];
  int v4478 = v4476[6];
  int v4486 = v4477 ^ v4478;
  v4476[19] = v4486;
  struct StateT * v4480 = slot_210(v4473);
  return v4480;
}

struct StateT * slot_3(struct StateT * v54) {
  int v55 = v54->timer;
  int v64 = v55 + 1;
  v54->timer = v64;
  int * v57 = v54->regs;
  int v58 = v57[2];
  int v59 = v57[9];
  int * v60 = v54->mem;
  int v69 = (int)((unsigned int)(v58 + 84) >> 2);
  v60[v69] = v59;
  struct StateT * v62 = slot_4(v54);
  return v62;
}

struct StateT * slot_264(struct StateT * v2568) {
  int v2569 = v2568->timer;
  int v2578 = v2569 + 1;
  v2568->timer = v2578;
  int * v2571 = v2568->regs;
  int v2572 = v2571[2];
  int * v2573 = v2568->mem;
  int v2582 = (int)((unsigned int)(v2572 + 84) >> 2);
  int v2574 = v2573[v2582];
  v2571[9] = v2574;
  struct StateT * v2576 = slot_265(v2568);
  return v2576;
}

struct StateT * slot_123(struct StateT * v3126) {
  int v3127 = v3126->timer;
  int v3135 = v3127 + 1;
  v3126->timer = v3135;
  int * v3129 = v3126->regs;
  int v3130 = v3129[17];
  int v3131 = v3129[6];
  int v3139 = v3130 | v3131;
  v3129[17] = v3139;
  struct StateT * v3133 = slot_124(v3126);
  return v3133;
}

struct StateT * slot_73(struct StateT * v1626) {
  int v1627 = v1626->timer;
  int v1635 = v1627 + 1;
  v1626->timer = v1635;
  int * v1629 = v1626->regs;
  int v1630 = v1629[1];
  int v1631 = v1629[19];
  int v1640 = v1630 + v1631;
  v1629[9] = v1640;
  struct StateT * v1633 = slot_74(v1626);
  return v1633;
}

struct StateT * slot_270(struct StateT * v2775) {
  int v2776 = v2775->timer;
  int v2785 = v2776 + 1;
  v2775->timer = v2785;
  int * v2778 = v2775->regs;
  int v2779 = v2778[2];
  int * v2780 = v2775->mem;
  int v2789 = (int)((unsigned int)(v2779 + 60) >> 2);
  int v2781 = v2780[v2789];
  v2778[23] = v2781;
  struct StateT * v2783 = slot_271(v2775);
  return v2783;
}

struct StateT * slot_198(struct StateT * v4305) {
  int v4306 = v4305->timer;
  int v4313 = v4306 + 1;
  v4305->timer = v4313;
  int * v4308 = v4305->regs;
  int v4309 = v4308[15];
  int v4317 = (int)((unsigned int)v4309 >> 14);
  v4308[9] = v4317;
  struct StateT * v4311 = slot_199(v4305);
  return v4311;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v26 = v17 + 1;
  v16->timer = v26;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[1];
  int * v22 = v16->mem;
  int v31 = (int)((unsigned int)(v20 + 92) >> 2);
  v22[v31] = v21;
  struct StateT * v24 = slot_2(v16);
  return v24;
}

struct StateT * slot_187(struct StateT * v4128) {
  int v4129 = v4128->timer;
  int v4137 = v4129 + 1;
  v4128->timer = v4137;
  int * v4131 = v4128->regs;
  int v4132 = v4131[14];
  int v4133 = v4131[11];
  int v4141 = v4132 ^ v4133;
  v4131[14] = v4141;
  struct StateT * v4135 = slot_188(v4128);
  return v4135;
}

struct StateT * slot_97(struct StateT * v2416) {
  int v2417 = v2416->timer;
  int v2425 = v2417 + 1;
  v2416->timer = v2425;
  int * v2419 = v2416->regs;
  int v2420 = v2419[15];
  int v2421 = v2419[20];
  int v2429 = v2420 | v2421;
  v2419[15] = v2429;
  struct StateT * v2423 = slot_98(v2416);
  return v2423;
}

struct StateT * slot_182(struct StateT * v4053) {
  int v4054 = v4053->timer;
  int v4061 = v4054 + 1;
  v4053->timer = v4061;
  int * v4056 = v4053->regs;
  int v4057 = v4056[6];
  int v4064 = v4057 << 13;
  v4056[6] = v4064;
  struct StateT * v4059 = slot_183(v4053);
  return v4059;
}

struct StateT * slot_38(struct StateT * v666) {
  int v667 = v666->timer;
  int v676 = v667 + 1;
  v666->timer = v676;
  int * v669 = v666->regs;
  int v670 = v669[2];
  int v671 = v669[5];
  int * v672 = v666->mem;
  int v681 = (int)((unsigned int)(v670 + 12) >> 2);
  v672[v681] = v671;
  struct StateT * v674 = slot_39(v666);
  return v674;
}

struct StateT * slot_178(struct StateT * v3993) {
  int v3994 = v3993->timer;
  int v4001 = v3994 + 1;
  v3993->timer = v4001;
  int * v3996 = v3993->regs;
  int v3997 = v3996[15];
  int v4005 = (int)((unsigned int)v3997 >> 19);
  v3996[9] = v4005;
  struct StateT * v3999 = slot_179(v3993);
  return v3999;
}

struct StateT * slot_106(struct StateT * v2722) {
  int v2723 = v2722->timer;
  int v2731 = v2723 + 1;
  v2722->timer = v2731;
  int * v2725 = v2722->regs;
  int v2726 = v2725[18];
  int v2727 = v2725[9];
  int v2736 = v2726 | v2727;
  v2725[6] = v2736;
  struct StateT * v2729 = slot_107(v2722);
  return v2729;
}

struct StateT * slot_98(struct StateT * v2451) {
  int v2452 = v2451->timer;
  int v2459 = v2452 + 1;
  v2451->timer = v2459;
  int * v2454 = v2451->regs;
  int v2455 = v2454[8];
  int v2463 = (int)((unsigned int)v2455 >> 19);
  v2454[20] = v2463;
  struct StateT * v2457 = slot_99(v2451);
  return v2457;
}

struct StateT * slot_159(struct StateT * v3696) {
  int v3697 = v3696->timer;
  int v3704 = v3697 + 1;
  v3696->timer = v3704;
  int * v3699 = v3696->regs;
  int v3700 = v3699[15];
  int v3707 = v3700 << 9;
  v3699[15] = v3707;
  struct StateT * v3702 = slot_160(v3696);
  return v3702;
}

struct StateT * slot_46(struct StateT * v810) {
  int v811 = v810->timer;
  int v818 = v811 + 1;
  v810->timer = v818;
  int * v813 = v810->regs;
  int v814 = v813[28];
  v813[27] = v814;
  struct StateT * v816 = slot_47(v810);
  return v816;
}

struct StateT * slot_212(struct StateT * v4519) {
  int v4520 = v4519->timer;
  int v4531 = v4520 + 1;
  v4519->timer = v4531;
  int * v4522 = v4519->regs;
  int v4523 = v4522[31];
  int v4524 = v4522[30];
  bool v4535 = (v4523 ^ -2147483648) >= (v4524 ^ -2147483648);
  struct StateT * v4529;
  if (v4535) {
    struct StateT * v4525 = slot_51(v4519);
    v4529 = v4525;
  } else {
    struct StateT * v4527 = slot_213(v4519);
    v4529 = v4527;
  }
  return v4529;
}

struct StateT * slot_132(struct StateT * v3269) {
  int v3270 = v3269->timer;
  int v3278 = v3270 + 1;
  v3269->timer = v3278;
  int * v3272 = v3269->regs;
  int v3273 = v3272[20];
  int v3274 = v3272[12];
  int v3283 = v3273 + v3274;
  v3272[11] = v3283;
  struct StateT * v3276 = slot_133(v3269);
  return v3276;
}

struct StateT * slot_130(struct StateT * v3236) {
  int v3237 = v3236->timer;
  int v3245 = v3237 + 1;
  v3236->timer = v3245;
  int * v3239 = v3236->regs;
  int v3240 = v3239[22];
  int v3241 = v3239[5];
  int v3249 = v3240 ^ v3241;
  v3239[22] = v3249;
  struct StateT * v3243 = slot_131(v3236);
  return v3243;
}

struct StateT * slot_211(struct StateT * v4505) {
  int v4506 = v4505->timer;
  int v4513 = v4506 + 1;
  v4505->timer = v4513;
  int * v4508 = v4505->regs;
  int v4509 = v4508[30];
  int v4516 = v4509 + 1;
  v4508[30] = v4516;
  struct StateT * v4511 = slot_212(v4505);
  return v4511;
}

struct StateT * slot_20(struct StateT * v371) {
  int v372 = v371->timer;
  int v381 = v372 + 1;
  v371->timer = v381;
  int * v374 = v371->regs;
  int v375 = v374[12];
  int * v376 = v371->mem;
  int v385 = (int)((unsigned int)(v375 + 20) >> 2);
  int v377 = v376[v385];
  v374[16] = v377;
  struct StateT * v379 = slot_21(v371);
  return v379;
}

struct StateT * slot_141(struct StateT * v3410) {
  int v3411 = v3410->timer;
  int v3418 = v3411 + 1;
  v3410->timer = v3418;
  int * v3413 = v3410->regs;
  int v3414 = v3413[16];
  int v3422 = (int)((unsigned int)v3414 >> 25);
  v3413[5] = v3422;
  struct StateT * v3416 = slot_142(v3410);
  return v3416;
}

struct StateT * slot_61(struct StateT * v1231) {
  int v1232 = v1231->timer;
  int v1239 = v1232 + 1;
  v1231->timer = v1239;
  int * v1234 = v1231->regs;
  int v1235 = v1234[18];
  int v1243 = (int)((unsigned int)v1235 >> 25);
  v1234[20] = v1243;
  struct StateT * v1237 = slot_62(v1231);
  return v1237;
}

struct StateT * slot_30(struct StateT * v543) {
  int v544 = v543->timer;
  int v551 = v544 + 1;
  v543->timer = v551;
  int * v546 = v543->regs;
  int v547 = v546[12];
  int v555 = v547 + -1947;
  v546[21] = v555;
  struct StateT * v549 = slot_31(v543);
  return v549;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v83 = v74 + 1;
  v73->timer = v83;
  int * v76 = v73->regs;
  int v77 = v76[2];
  int v78 = v76[18];
  int * v79 = v73->mem;
  int v88 = (int)((unsigned int)(v77 + 80) >> 2);
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
  int v347 = (int)((unsigned int)(v337 + 12) >> 2);
  int v339 = v338[v347];
  v336[6] = v339;
  struct StateT * v341 = slot_19(v333);
  return v341;
}

struct StateT * slot_9(struct StateT * v168) {
  int v169 = v168->timer;
  int v178 = v169 + 1;
  v168->timer = v178;
  int * v171 = v168->regs;
  int v172 = v171[2];
  int v173 = v171[23];
  int * v174 = v168->mem;
  int v183 = (int)((unsigned int)(v172 + 60) >> 2);
  v174[v183] = v173;
  struct StateT * v176 = slot_10(v168);
  return v176;
}

struct StateT * slot_183(struct StateT * v4067) {
  int v4068 = v4067->timer;
  int v4076 = v4068 + 1;
  v4067->timer = v4076;
  int * v4070 = v4067->regs;
  int v4071 = v4070[6];
  int v4072 = v4070[9];
  int v4080 = v4071 | v4072;
  v4070[6] = v4080;
  struct StateT * v4074 = slot_184(v4067);
  return v4074;
}

struct StateT * slot_240(struct StateT * v1762) {
  int v1763 = v1762->timer;
  int v1770 = v1763 + 1;
  v1762->timer = v1770;
  int * v1765 = v1762->regs;
  int v1766 = v1765[7];
  int v1773 = v1766 + -718;
  v1765[7] = v1773;
  struct StateT * v1768 = slot_241(v1762);
  return v1768;
}

struct StateT * slot_247(struct StateT * v1978) {
  int v1979 = v1978->timer;
  int v1988 = v1979 + 1;
  v1978->timer = v1988;
  int * v1981 = v1978->regs;
  int v1982 = v1981[10];
  int v1983 = v1981[29];
  int * v1984 = v1978->mem;
  int v1993 = (int)((unsigned int)(v1982 + 4) >> 2);
  v1984[v1993] = v1983;
  struct StateT * v1986 = slot_248(v1978);
  return v1986;
}

struct StateT * slot_43(struct StateT * v761) {
  int v762 = v761->timer;
  int v771 = v762 + 1;
  v761->timer = v771;
  int * v764 = v761->regs;
  int v765 = v764[2];
  int v766 = v764[6];
  int * v767 = v761->mem;
  int v776 = (int)((unsigned int)(v765 + 8) >> 2);
  v767[v776] = v766;
  struct StateT * v769 = slot_44(v761);
  return v769;
}

struct StateT * slot_70(struct StateT * v1522) {
  int v1523 = v1522->timer;
  int v1531 = v1523 + 1;
  v1522->timer = v1531;
  int * v1525 = v1522->regs;
  int v1526 = v1525[14];
  int v1527 = v1525[8];
  int v1535 = v1526 ^ v1527;
  v1525[14] = v1535;
  struct StateT * v1529 = slot_71(v1522);
  return v1529;
}

struct StateT * slot_168(struct StateT * v3832) {
  int v3833 = v3832->timer;
  int v3841 = v3833 + 1;
  v3832->timer = v3841;
  int * v3835 = v3832->regs;
  int v3836 = v3835[25];
  int v3837 = v3835[15];
  int v3845 = v3836 ^ v3837;
  v3835[25] = v3845;
  struct StateT * v3839 = slot_169(v3832);
  return v3839;
}

struct StateT * slot_76(struct StateT * v1718) {
  int v1719 = v1718->timer;
  int v1726 = v1719 + 1;
  v1718->timer = v1726;
  int * v1721 = v1718->regs;
  int v1722 = v1721[15];
  int v1729 = v1722 << 9;
  v1721[15] = v1729;
  struct StateT * v1724 = slot_77(v1718);
  return v1724;
}

struct StateT * slot_6(struct StateT * v111) {
  int v112 = v111->timer;
  int v121 = v112 + 1;
  v111->timer = v121;
  int * v114 = v111->regs;
  int v115 = v114[2];
  int v116 = v114[20];
  int * v117 = v111->mem;
  int v126 = (int)((unsigned int)(v115 + 72) >> 2);
  v117[v126] = v116;
  struct StateT * v119 = slot_7(v111);
  return v119;
}

struct StateT * slot_225(struct StateT * v1279) {
  int v1280 = v1279->timer;
  int v1288 = v1280 + 1;
  v1279->timer = v1288;
  int * v1282 = v1279->regs;
  int v1283 = v1282[26];
  int v1284 = v1282[7];
  int v1292 = v1283 + v1284;
  v1282[26] = v1292;
  struct StateT * v1286 = slot_226(v1279);
  return v1286;
}

struct StateT * slot_55(struct StateT * v1042) {
  int v1043 = v1042->timer;
  int v1050 = v1043 + 1;
  v1042->timer = v1050;
  int * v1045 = v1042->regs;
  int v1046 = v1045[15];
  int v1054 = (int)((unsigned int)v1046 >> 25);
  v1045[9] = v1054;
  struct StateT * v1048 = slot_56(v1042);
  return v1048;
}

struct StateT * slot_213(struct StateT * v894) {
  int v895 = v894->timer;
  int v903 = v895 + 1;
  v894->timer = v903;
  int * v897 = v894->regs;
  int v898 = v897[23];
  int v899 = v897[29];
  int v907 = v898 + v899;
  v897[29] = v907;
  struct StateT * v901 = slot_214(v894);
  return v901;
}

struct StateT * slot_82(struct StateT * v1898) {
  int v1899 = v1898->timer;
  int v1906 = v1899 + 1;
  v1898->timer = v1906;
  int * v1901 = v1898->regs;
  int v1902 = v1901[9];
  int v1909 = v1902 << 9;
  v1901[9] = v1909;
  struct StateT * v1904 = slot_83(v1898);
  return v1904;
}

struct StateT * slot_274(struct StateT * v2918) {
  int v2919 = v2918->timer;
  int v2928 = v2919 + 1;
  v2918->timer = v2928;
  int * v2921 = v2918->regs;
  int v2922 = v2921[2];
  int * v2923 = v2918->mem;
  int v2932 = (int)((unsigned int)(v2922 + 44) >> 2);
  int v2924 = v2923[v2932];
  v2921[27] = v2924;
  struct StateT * v2926 = slot_275(v2918);
  return v2926;
}

struct StateT * slot_263(struct StateT * v2534) {
  int v2535 = v2534->timer;
  int v2544 = v2535 + 1;
  v2534->timer = v2544;
  int * v2537 = v2534->regs;
  int v2538 = v2537[2];
  int * v2539 = v2534->mem;
  int v2548 = (int)((unsigned int)(v2538 + 88) >> 2);
  int v2540 = v2539[v2548];
  v2537[8] = v2540;
  struct StateT * v2542 = slot_264(v2534);
  return v2542;
}

struct StateT * slot_161(struct StateT * v3726) {
  int v3727 = v3726->timer;
  int v3734 = v3727 + 1;
  v3726->timer = v3734;
  int * v3729 = v3726->regs;
  int v3730 = v3729[6];
  int v3738 = (int)((unsigned int)v3730 >> 23);
  v3729[9] = v3738;
  struct StateT * v3732 = slot_162(v3726);
  return v3732;
}

struct StateT * slot_185(struct StateT * v4098) {
  int v4099 = v4098->timer;
  int v4106 = v4099 + 1;
  v4098->timer = v4106;
  int * v4101 = v4098->regs;
  int v4102 = v4101[8];
  int v4109 = v4102 << 13;
  v4101[8] = v4109;
  struct StateT * v4104 = slot_186(v4098);
  return v4104;
}

struct StateT * slot_91(struct StateT * v2205) {
  int v2206 = v2205->timer;
  int v2214 = v2206 + 1;
  v2205->timer = v2214;
  int * v2208 = v2205->regs;
  int v2209 = v2208[26];
  int v2210 = v2208[12];
  int v2219 = v2209 + v2210;
  v2208[15] = v2219;
  struct StateT * v2212 = slot_92(v2205);
  return v2212;
}

struct StateT * slot_58(struct StateT * v1135) {
  int v1136 = v1135->timer;
  int v1143 = v1136 + 1;
  v1135->timer = v1143;
  int * v1138 = v1135->regs;
  int v1139 = v1138[20];
  int v1147 = (int)((unsigned int)v1139 >> 25);
  v1138[9] = v1147;
  struct StateT * v1141 = slot_59(v1135);
  return v1141;
}

struct StateT * slot_89(struct StateT * v2135) {
  int v2136 = v2135->timer;
  int v2144 = v2136 + 1;
  v2135->timer = v2144;
  int * v2138 = v2135->regs;
  int v2139 = v2138[27];
  int v2140 = v2138[9];
  int v2148 = v2139 ^ v2140;
  v2138[27] = v2148;
  struct StateT * v2142 = slot_90(v2135);
  return v2142;
}

struct StateT * slot_255(struct StateT * v2258) {
  int v2259 = v2258->timer;
  int v2268 = v2259 + 1;
  v2258->timer = v2268;
  int * v2261 = v2258->regs;
  int v2262 = v2261[10];
  int v2263 = v2261[13];
  int * v2264 = v2258->mem;
  int v2273 = (int)((unsigned int)(v2262 + 36) >> 2);
  v2264[v2273] = v2263;
  struct StateT * v2266 = slot_256(v2258);
  return v2266;
}

struct StateT * slot_66(struct StateT * v1388) {
  int v1389 = v1388->timer;
  int v1397 = v1389 + 1;
  v1388->timer = v1397;
  int * v1391 = v1388->regs;
  int v1392 = v1391[8];
  int v1393 = v1391[20];
  int v1401 = v1392 | v1393;
  v1391[8] = v1401;
  struct StateT * v1395 = slot_67(v1388);
  return v1395;
}

struct StateT * slot_140(struct StateT * v3394) {
  int v3395 = v3394->timer;
  int v3403 = v3395 + 1;
  v3394->timer = v3403;
  int * v3397 = v3394->regs;
  int v3398 = v3397[11];
  int v3399 = v3397[5];
  int v3407 = v3398 | v3399;
  v3397[11] = v3407;
  struct StateT * v3401 = slot_141(v3394);
  return v3401;
}

struct StateT * slot_265(struct StateT * v2601) {
  int v2602 = v2601->timer;
  int v2611 = v2602 + 1;
  v2601->timer = v2611;
  int * v2604 = v2601->regs;
  int v2605 = v2604[2];
  int * v2606 = v2601->mem;
  int v2615 = (int)((unsigned int)(v2605 + 80) >> 2);
  int v2607 = v2606[v2615];
  v2604[18] = v2607;
  struct StateT * v2609 = slot_266(v2601);
  return v2609;
}

struct StateT * slot_49(struct StateT * v859) {
  int v860 = v859->timer;
  int v867 = v860 + 1;
  v859->timer = v867;
  int * v862 = v859->regs;
  int v863 = v862[15];
  v862[13] = v863;
  struct StateT * v865 = slot_50(v859);
  return v865;
}

struct StateT * slot_216(struct StateT * v990) {
  int v991 = v990->timer;
  int v999 = v991 + 1;
  v990->timer = v999;
  int * v993 = v990->regs;
  int v994 = v993[14];
  int v995 = v993[7];
  int v1003 = v994 + v995;
  v993[14] = v1003;
  struct StateT * v997 = slot_217(v990);
  return v997;
}

struct StateT * slot_50(struct StateT * v874) {
  int v875 = v874->timer;
  int v885 = v875 + 1;
  v874->timer = v885;
  int * v877 = v874->regs;
  int v878 = v877[31];
  bool v888 = (v878 ^ -2147483648) < -2147483648;
  struct StateT * v883;
  if (v888) {
    struct StateT * v879 = slot_213(v874);
    v883 = v879;
  } else {
    struct StateT * v881 = slot_51(v874);
    v883 = v881;
  }
  return v883;
}

struct StateT * slot_37(struct StateT * v647) {
  int v648 = v647->timer;
  int v657 = v648 + 1;
  v647->timer = v657;
  int * v650 = v647->regs;
  int v651 = v650[2];
  int v652 = v650[25];
  int * v653 = v647->mem;
  int v662 = (int)((unsigned int)(v651 + 16) >> 2);
  v653[v662] = v652;
  struct StateT * v655 = slot_38(v647);
  return v655;
}

struct StateT * slot_114(struct StateT * v2990) {
  int v2991 = v2990->timer;
  int v2999 = v2991 + 1;
  v2990->timer = v2999;
  int * v2993 = v2990->regs;
  int v2994 = v2993[8];
  int v2995 = v2993[25];
  int v3004 = v2994 + v2995;
  v2993[5] = v3004;
  struct StateT * v2997 = slot_115(v2990);
  return v2997;
}

struct StateT * slot_135(struct StateT * v3320) {
  int v3321 = v3320->timer;
  int v3328 = v3321 + 1;
  v3320->timer = v3328;
  int * v3323 = v3320->regs;
  int v3324 = v3323[15];
  int v3332 = (int)((unsigned int)v3324 >> 25);
  v3323[5] = v3332;
  struct StateT * v3326 = slot_136(v3320);
  return v3326;
}

struct StateT * slot_248(struct StateT * v2011) {
  int v2012 = v2011->timer;
  int v2021 = v2012 + 1;
  v2011->timer = v2021;
  int * v2014 = v2011->regs;
  int v2015 = v2014[10];
  int v2016 = v2014[28];
  int * v2017 = v2011->mem;
  int v2026 = (int)((unsigned int)(v2015 + 8) >> 2);
  v2017[v2026] = v2016;
  struct StateT * v2019 = slot_249(v2011);
  return v2019;
}

struct StateT * slot_257(struct StateT * v2330) {
  int v2331 = v2330->timer;
  int v2340 = v2331 + 1;
  v2330->timer = v2340;
  int * v2333 = v2330->regs;
  int v2334 = v2333[10];
  int v2335 = v2333[17];
  int * v2336 = v2330->mem;
  int v2345 = (int)((unsigned int)(v2334 + 44) >> 2);
  v2336[v2345] = v2335;
  struct StateT * v2338 = slot_258(v2330);
  return v2338;
}

struct StateT * slot_59(struct StateT * v1166) {
  int v1167 = v1166->timer;
  int v1174 = v1167 + 1;
  v1166->timer = v1174;
  int * v1169 = v1166->regs;
  int v1170 = v1169[20];
  int v1177 = v1170 << 7;
  v1169[20] = v1177;
  struct StateT * v1172 = slot_60(v1166);
  return v1172;
}

struct StateT * slot_192(struct StateT * v4209) {
  int v4210 = v4209->timer;
  int v4218 = v4210 + 1;
  v4209->timer = v4218;
  int * v4212 = v4209->regs;
  int v4213 = v4212[12];
  int v4214 = v4212[25];
  int v4223 = v4213 + v4214;
  v4212[15] = v4223;
  struct StateT * v4216 = slot_193(v4209);
  return v4216;
}

struct StateT * slot_40(struct StateT * v704) {
  int v705 = v704->timer;
  int v714 = v705 + 1;
  v704->timer = v714;
  int * v707 = v704->regs;
  int v708 = v707[2];
  int v709 = v707[24];
  int * v710 = v704->mem;
  int v719 = (int)((unsigned int)(v708 + 36) >> 2);
  v710[v719] = v709;
  struct StateT * v712 = slot_41(v704);
  return v712;
}

struct StateT * slot_48(struct StateT * v840) {
  int v841 = v840->timer;
  int v850 = v841 + 1;
  v840->timer = v850;
  int * v843 = v840->regs;
  int v844 = v843[2];
  int v845 = v843[15];
  int * v846 = v840->mem;
  int v855 = (int)((unsigned int)(v844 + 24) >> 2);
  v846[v855] = v845;
  struct StateT * v848 = slot_49(v840);
  return v848;
}

struct StateT * slot_77(struct StateT * v1746) {
  int v1747 = v1746->timer;
  int v1755 = v1747 + 1;
  v1746->timer = v1755;
  int * v1749 = v1746->regs;
  int v1750 = v1749[15];
  int v1751 = v1749[20];
  int v1759 = v1750 | v1751;
  v1749[15] = v1759;
  struct StateT * v1753 = slot_78(v1746);
  return v1753;
}

struct StateT * slot_85(struct StateT * v1997) {
  int v1998 = v1997->timer;
  int v2005 = v1998 + 1;
  v1997->timer = v2005;
  int * v2000 = v1997->regs;
  int v2001 = v2000[18];
  int v2008 = v2001 << 9;
  v2000[18] = v2008;
  struct StateT * v2003 = slot_86(v1997);
  return v2003;
}

struct StateT * slot_75(struct StateT * v1689) {
  int v1690 = v1689->timer;
  int v1697 = v1690 + 1;
  v1689->timer = v1697;
  int * v1692 = v1689->regs;
  int v1693 = v1692[15];
  int v1701 = (int)((unsigned int)v1693 >> 23);
  v1692[20] = v1701;
  struct StateT * v1695 = slot_76(v1689);
  return v1695;
}

struct StateT * slot_72(struct StateT * v1590) {
  int v1591 = v1590->timer;
  int v1599 = v1591 + 1;
  v1590->timer = v1599;
  int * v1593 = v1590->regs;
  int v1594 = v1593[13];
  int v1595 = v1593[11];
  int v1604 = v1594 + v1595;
  v1593[8] = v1604;
  struct StateT * v1597 = slot_73(v1590);
  return v1597;
}

struct StateT * slot_119(struct StateT * v3067) {
  int v3068 = v3067->timer;
  int v3075 = v3068 + 1;
  v3067->timer = v3075;
  int * v3070 = v3067->regs;
  int v3071 = v3070[16];
  int v3078 = v3071 << 18;
  v3070[16] = v3078;
  struct StateT * v3073 = slot_120(v3067);
  return v3073;
}

struct StateT * slot_71(struct StateT * v1557) {
  int v1558 = v1557->timer;
  int v1566 = v1558 + 1;
  v1557->timer = v1566;
  int * v1560 = v1557->regs;
  int v1561 = v1560[12];
  int v1562 = v1560[21];
  int v1571 = v1561 + v1562;
  v1560[15] = v1571;
  struct StateT * v1564 = slot_72(v1557);
  return v1564;
}

struct StateT * slot_101(struct StateT * v2553) {
  int v2554 = v2553->timer;
  int v2561 = v2554 + 1;
  v2553->timer = v2561;
  int * v2556 = v2553->regs;
  int v2557 = v2556[9];
  int v2565 = (int)((unsigned int)v2557 >> 19);
  v2556[20] = v2565;
  struct StateT * v2559 = slot_102(v2553);
  return v2559;
}

struct StateT * slot_276(struct StateT * v2985) {
  int v2986 = v2985->timer;
  int v2989 = v2986 + 1;
  v2985->timer = v2989;
  return v2985;
}

struct StateT * slot_108(struct StateT * v2794) {
  int v2795 = v2794->timer;
  int v2803 = v2795 + 1;
  v2794->timer = v2803;
  int * v2797 = v2794->regs;
  int v2798 = v2797[23];
  int v2799 = v2797[8];
  int v2807 = v2798 ^ v2799;
  v2797[23] = v2807;
  struct StateT * v2801 = slot_109(v2794);
  return v2801;
}

struct StateT * slot_116(struct StateT * v3022) {
  int v3023 = v3022->timer;
  int v3030 = v3023 + 1;
  v3022->timer = v3030;
  int * v3025 = v3022->regs;
  int v3026 = v3025[15];
  int v3033 = v3026 << 18;
  v3025[15] = v3033;
  struct StateT * v3028 = slot_117(v3022);
  return v3028;
}

struct StateT * slot_93(struct StateT * v2277) {
  int v2278 = v2277->timer;
  int v2286 = v2278 + 1;
  v2277->timer = v2286;
  int * v2280 = v2277->regs;
  int v2281 = v2280[27];
  int v2282 = v2280[1];
  int v2291 = v2281 + v2282;
  v2280[9] = v2291;
  struct StateT * v2284 = slot_94(v2277);
  return v2284;
}

struct StateT * slot_266(struct StateT * v2636) {
  int v2637 = v2636->timer;
  int v2646 = v2637 + 1;
  v2636->timer = v2646;
  int * v2639 = v2636->regs;
  int v2640 = v2639[2];
  int * v2641 = v2636->mem;
  int v2650 = (int)((unsigned int)(v2640 + 76) >> 2);
  int v2642 = v2641[v2650];
  v2639[19] = v2642;
  struct StateT * v2644 = slot_267(v2636);
  return v2644;
}

struct StateT * slot_88(struct StateT * v2100) {
  int v2101 = v2100->timer;
  int v2109 = v2101 + 1;
  v2100->timer = v2109;
  int * v2103 = v2100->regs;
  int v2104 = v2103[24];
  int v2105 = v2103[8];
  int v2113 = v2104 ^ v2105;
  v2103[24] = v2113;
  struct StateT * v2107 = slot_89(v2100);
  return v2107;
}

struct StateT * slot_96(struct StateT * v2383) {
  int v2384 = v2383->timer;
  int v2391 = v2384 + 1;
  v2383->timer = v2391;
  int * v2386 = v2383->regs;
  int v2387 = v2386[15];
  int v2394 = v2387 << 13;
  v2386[15] = v2394;
  struct StateT * v2389 = slot_97(v2383);
  return v2389;
}

struct StateT * slot_215(struct StateT * v960) {
  int v961 = v960->timer;
  int v967 = v961 + 1;
  v960->timer = v967;
  int * v963 = v960->regs;
  v963[15] = 1634762752;
  struct StateT * v965 = slot_216(v960);
  return v965;
}

struct StateT * slot_234(struct StateT * v1574) {
  int v1575 = v1574->timer;
  int v1583 = v1575 + 1;
  v1574->timer = v1583;
  int * v1577 = v1574->regs;
  int v1578 = v1577[24];
  int v1579 = v1577[30];
  int v1587 = v1578 + v1579;
  v1577[24] = v1587;
  struct StateT * v1581 = slot_235(v1574);
  return v1581;
}

struct StateT * slot_45(struct StateT * v795) {
  int v796 = v795->timer;
  int v803 = v796 + 1;
  v795->timer = v803;
  int * v798 = v795->regs;
  int v799 = v798[7];
  v798[14] = v799;
  struct StateT * v801 = slot_46(v795);
  return v801;
}

struct StateT * slot_218(struct StateT * v1057) {
  int v1058 = v1057->timer;
  int v1066 = v1058 + 1;
  v1057->timer = v1066;
  int * v1060 = v1057->regs;
  int v1061 = v1060[12];
  int v1062 = v1060[6];
  int v1070 = v1061 + v1062;
  v1060[12] = v1070;
  struct StateT * v1064 = slot_219(v1057);
  return v1064;
}

struct StateT * slot_220(struct StateT * v1116) {
  int v1117 = v1116->timer;
  int v1126 = v1117 + 1;
  v1116->timer = v1126;
  int * v1119 = v1116->regs;
  int v1120 = v1119[2];
  int * v1121 = v1116->mem;
  int v1130 = (int)((unsigned int)(v1120 + 12) >> 2);
  int v1122 = v1121[v1130];
  v1119[7] = v1122;
  struct StateT * v1124 = slot_221(v1116);
  return v1124;
}

struct StateT * slot_134(struct StateT * v3303) {
  int v3304 = v3303->timer;
  int v3312 = v3304 + 1;
  v3303->timer = v3312;
  int * v3306 = v3303->regs;
  int v3307 = v3306[22];
  int v3308 = v3306[1];
  int v3317 = v3307 + v3308;
  v3306[17] = v3317;
  struct StateT * v3310 = slot_135(v3303);
  return v3310;
}

struct StateT * slot_175(struct StateT * v3948) {
  int v3949 = v3948->timer;
  int v3956 = v3949 + 1;
  v3948->timer = v3956;
  int * v3951 = v3948->regs;
  int v3952 = v3951[11];
  int v3960 = (int)((unsigned int)v3952 >> 19);
  v3951[9] = v3960;
  struct StateT * v3954 = slot_176(v3948);
  return v3954;
}

struct StateT * slot_273(struct StateT * v2882) {
  int v2883 = v2882->timer;
  int v2892 = v2883 + 1;
  v2882->timer = v2892;
  int * v2885 = v2882->regs;
  int v2886 = v2885[2];
  int * v2887 = v2882->mem;
  int v2896 = (int)((unsigned int)(v2886 + 48) >> 2);
  int v2888 = v2887[v2896];
  v2885[26] = v2888;
  struct StateT * v2890 = slot_274(v2882);
  return v2890;
}

struct StateT * slot_69(struct StateT * v1490) {
  int v1491 = v1490->timer;
  int v1499 = v1491 + 1;
  v1490->timer = v1499;
  int * v1493 = v1490->regs;
  int v1494 = v1493[1];
  int v1495 = v1493[18];
  int v1503 = v1494 ^ v1495;
  v1493[1] = v1503;
  struct StateT * v1497 = slot_70(v1490);
  return v1497;
}

struct StateT * slot_202(struct StateT * v4365) {
  int v4366 = v4365->timer;
  int v4373 = v4366 + 1;
  v4365->timer = v4373;
  int * v4368 = v4365->regs;
  int v4369 = v4368[6];
  int v4376 = v4369 << 18;
  v4368[6] = v4376;
  struct StateT * v4371 = slot_203(v4365);
  return v4371;
}

struct StateT * slot_230(struct StateT * v1439) {
  int v1440 = v1439->timer;
  int v1448 = v1440 + 1;
  v1439->timer = v1448;
  int * v1442 = v1439->regs;
  int v1443 = v1442[17];
  int v1444 = v1442[30];
  int v1452 = v1443 + v1444;
  v1442[17] = v1452;
  struct StateT * v1446 = slot_231(v1439);
  return v1446;
}

struct StateT * slot_188(struct StateT * v4144) {
  int v4145 = v4144->timer;
  int v4153 = v4145 + 1;
  v4144->timer = v4153;
  int * v4147 = v4144->regs;
  int v4148 = v4147[12];
  int v4149 = v4147[15];
  int v4157 = v4148 ^ v4149;
  v4147[12] = v4157;
  struct StateT * v4151 = slot_189(v4144);
  return v4151;
}

struct StateT * slot_138(struct StateT * v3365) {
  int v3366 = v3365->timer;
  int v3373 = v3366 + 1;
  v3365->timer = v3373;
  int * v3368 = v3365->regs;
  int v3369 = v3368[11];
  int v3377 = (int)((unsigned int)v3369 >> 25);
  v3368[5] = v3377;
  struct StateT * v3371 = slot_139(v3365);
  return v3371;
}

struct StateT * slot_186(struct StateT * v4112) {
  int v4113 = v4112->timer;
  int v4121 = v4113 + 1;
  v4112->timer = v4121;
  int * v4115 = v4112->regs;
  int v4116 = v4115[8];
  int v4117 = v4115[9];
  int v4125 = v4116 | v4117;
  v4115[8] = v4125;
  struct StateT * v4119 = slot_187(v4112);
  return v4119;
}

struct StateT * slot_102(struct StateT * v2587) {
  int v2588 = v2587->timer;
  int v2595 = v2588 + 1;
  v2587->timer = v2595;
  int * v2590 = v2587->regs;
  int v2591 = v2590[9];
  int v2598 = v2591 << 13;
  v2590[9] = v2598;
  struct StateT * v2593 = slot_103(v2587);
  return v2593;
}

struct StateT * slot_145(struct StateT * v3470) {
  int v3471 = v3470->timer;
  int v3478 = v3471 + 1;
  v3470->timer = v3478;
  int * v3473 = v3470->regs;
  int v3474 = v3473[17];
  int v3481 = v3474 << 7;
  v3473[17] = v3481;
  struct StateT * v3476 = slot_146(v3470);
  return v3476;
}

struct StateT * slot_110(struct StateT * v2865) {
  int v2866 = v2865->timer;
  int v2874 = v2866 + 1;
  v2865->timer = v2874;
  int * v2868 = v2865->regs;
  int v2869 = v2868[17];
  int v2870 = v2868[6];
  int v2879 = v2869 ^ v2870;
  v2868[8] = v2879;
  struct StateT * v2872 = slot_111(v2865);
  return v2872;
}

struct StateT * slot_196(struct StateT * v4275) {
  int v4276 = v4275->timer;
  int v4283 = v4276 + 1;
  v4275->timer = v4283;
  int * v4278 = v4275->regs;
  int v4279 = v4278[11];
  int v4286 = v4279 << 18;
  v4278[11] = v4286;
  struct StateT * v4281 = slot_197(v4275);
  return v4281;
}

struct StateT * slot_208(struct StateT * v4456) {
  int v4457 = v4456->timer;
  int v4465 = v4457 + 1;
  v4456->timer = v4465;
  int * v4459 = v4456->regs;
  int v4460 = v4459[20];
  int v4461 = v4459[15];
  int v4470 = v4460 ^ v4461;
  v4459[11] = v4470;
  struct StateT * v4463 = slot_209(v4456);
  return v4463;
}

struct StateT * slot_172(struct StateT * v3897) {
  int v3898 = v3897->timer;
  int v3906 = v3898 + 1;
  v3897->timer = v3906;
  int * v3900 = v3897->regs;
  int v3901 = v3900[25];
  int v3902 = v3900[5];
  int v3911 = v3901 + v3902;
  v3900[15] = v3911;
  struct StateT * v3904 = slot_173(v3897);
  return v3904;
}

struct StateT * slot_131(struct StateT * v3252) {
  int v3253 = v3252->timer;
  int v3261 = v3253 + 1;
  v3252->timer = v3261;
  int * v3255 = v3252->regs;
  int v3256 = v3255[21];
  int v3257 = v3255[14];
  int v3266 = v3256 + v3257;
  v3255[15] = v3266;
  struct StateT * v3259 = slot_132(v3252);
  return v3259;
}

struct StateT * slot_8(struct StateT * v149) {
  int v150 = v149->timer;
  int v159 = v150 + 1;
  v149->timer = v159;
  int * v152 = v149->regs;
  int v153 = v152[2];
  int v154 = v152[22];
  int * v155 = v149->mem;
  int v164 = (int)((unsigned int)(v153 + 64) >> 2);
  v155[v164] = v154;
  struct StateT * v157 = slot_9(v149);
  return v157;
}

struct StateT * slot_180(struct StateT * v4022) {
  int v4023 = v4022->timer;
  int v4031 = v4023 + 1;
  v4022->timer = v4031;
  int * v4025 = v4022->regs;
  int v4026 = v4025[15];
  int v4027 = v4025[9];
  int v4035 = v4026 | v4027;
  v4025[15] = v4035;
  struct StateT * v4029 = slot_181(v4022);
  return v4029;
}

struct StateT * slot_203(struct StateT * v4379) {
  int v4380 = v4379->timer;
  int v4388 = v4380 + 1;
  v4379->timer = v4388;
  int * v4382 = v4379->regs;
  int v4383 = v4382[6];
  int v4384 = v4382[9];
  int v4392 = v4383 | v4384;
  v4382[6] = v4392;
  struct StateT * v4386 = slot_204(v4379);
  return v4386;
}

struct StateT * slot_190(struct StateT * v4176) {
  int v4177 = v4176->timer;
  int v4185 = v4177 + 1;
  v4176->timer = v4185;
  int * v4179 = v4176->regs;
  int v4180 = v4179[1];
  int v4181 = v4179[8];
  int v4189 = v4180 ^ v4181;
  v4179[1] = v4189;
  struct StateT * v4183 = slot_191(v4176);
  return v4183;
}

struct StateT * slot_157(struct StateT * v3665) {
  int v3666 = v3665->timer;
  int v3674 = v3666 + 1;
  v3665->timer = v3674;
  int * v3668 = v3665->regs;
  int v3669 = v3668[11];
  int v3670 = v3668[9];
  int v3678 = v3669 | v3670;
  v3668[11] = v3678;
  struct StateT * v3672 = slot_158(v3665);
  return v3672;
}

struct StateT * slot_242(struct StateT * v1819) {
  int v1820 = v1819->timer;
  int v1828 = v1820 + 1;
  v1819->timer = v1828;
  int * v1822 = v1819->regs;
  int v1823 = v1822[21];
  int v1824 = v1822[15];
  int v1832 = v1823 + v1824;
  v1822[15] = v1832;
  struct StateT * v1826 = slot_243(v1819);
  return v1826;
}

struct StateT * slot_200(struct StateT * v4334) {
  int v4335 = v4334->timer;
  int v4343 = v4335 + 1;
  v4334->timer = v4343;
  int * v4337 = v4334->regs;
  int v4338 = v4337[15];
  int v4339 = v4337[9];
  int v4347 = v4338 | v4339;
  v4337[15] = v4347;
  struct StateT * v4341 = slot_201(v4334);
  return v4341;
}

struct StateT * slot_243(struct StateT * v1851) {
  int v1852 = v1851->timer;
  int v1860 = v1852 + 1;
  v1851->timer = v1860;
  int * v1854 = v1851->regs;
  int v1855 = v1854[11];
  int v1856 = v1854[6];
  int v1864 = v1855 + v1856;
  v1854[11] = v1864;
  struct StateT * v1858 = slot_244(v1851);
  return v1858;
}

struct StateT * slot_173(struct StateT * v3914) {
  int v3915 = v3914->timer;
  int v3923 = v3915 + 1;
  v3914->timer = v3923;
  int * v3917 = v3914->regs;
  int v3918 = v3917[26];
  int v3919 = v3917[17];
  int v3928 = v3918 + v3919;
  v3917[6] = v3928;
  struct StateT * v3921 = slot_174(v3914);
  return v3921;
}

struct StateT * slot_149(struct StateT * v3534) {
  int v3535 = v3534->timer;
  int v3543 = v3535 + 1;
  v3534->timer = v3543;
  int * v3537 = v3534->regs;
  int v3538 = v3537[8];
  int v3539 = v3537[16];
  int v3548 = v3538 ^ v3539;
  v3537[17] = v3548;
  struct StateT * v3541 = slot_150(v3534);
  return v3541;
}

struct StateT * slot_5(struct StateT * v92) {
  int v93 = v92->timer;
  int v102 = v93 + 1;
  v92->timer = v102;
  int * v95 = v92->regs;
  int v96 = v95[2];
  int v97 = v95[19];
  int * v98 = v92->mem;
  int v107 = (int)((unsigned int)(v96 + 76) >> 2);
  v98[v107] = v97;
  struct StateT * v100 = slot_6(v92);
  return v100;
}

struct StateT * slot_104(struct StateT * v2655) {
  int v2656 = v2655->timer;
  int v2663 = v2656 + 1;
  v2655->timer = v2663;
  int * v2658 = v2655->regs;
  int v2659 = v2658[18];
  int v2667 = (int)((unsigned int)v2659 >> 19);
  v2658[9] = v2667;
  struct StateT * v2661 = slot_105(v2655);
  return v2661;
}

struct StateT * slot_235(struct StateT * v1607) {
  int v1608 = v1607->timer;
  int v1617 = v1608 + 1;
  v1607->timer = v1617;
  int * v1610 = v1607->regs;
  int v1611 = v1610[2];
  int * v1612 = v1607->mem;
  int v1621 = (int)((unsigned int)(v1611 + 40) >> 2);
  int v1613 = v1612[v1621];
  v1610[30] = v1613;
  struct StateT * v1615 = slot_236(v1607);
  return v1615;
}

struct StateT * slot_275(struct StateT * v2954) {
  int v2955 = v2954->timer;
  int v2962 = v2955 + 1;
  v2954->timer = v2962;
  int * v2957 = v2954->regs;
  int v2958 = v2957[2];
  int v2965 = v2958 + 96;
  v2957[2] = v2965;
  struct StateT * v2960 = slot_276(v2954);
  return v2960;
}

struct StateT * slot_54(struct StateT * v1006) {
  int v1007 = v1006->timer;
  int v1015 = v1007 + 1;
  v1006->timer = v1015;
  int * v1009 = v1006->regs;
  int v1010 = v1009[22];
  int v1011 = v1009[17];
  int v1020 = v1010 + v1011;
  v1009[8] = v1020;
  struct StateT * v1013 = slot_55(v1006);
  return v1013;
}

struct StateT * slot_26(struct StateT * v485) {
  int v486 = v485->timer;
  int v495 = v486 + 1;
  v485->timer = v495;
  int * v488 = v485->regs;
  int v489 = v488[11];
  int * v490 = v485->mem;
  int v499 = (int)((unsigned int)(v489 + 12) >> 2);
  int v491 = v490[v499];
  v488[15] = v491;
  struct StateT * v493 = slot_27(v485);
  return v493;
}

struct StateT * slot_206(struct StateT * v4424) {
  int v4425 = v4424->timer;
  int v4433 = v4425 + 1;
  v4424->timer = v4433;
  int * v4427 = v4424->regs;
  int v4428 = v4427[8];
  int v4429 = v4427[9];
  int v4437 = v4428 | v4429;
  v4427[8] = v4437;
  struct StateT * v4431 = slot_207(v4424);
  return v4431;
}

struct StateT * slot_227(struct StateT * v1345) {
  int v1346 = v1345->timer;
  int v1354 = v1346 + 1;
  v1345->timer = v1354;
  int * v1348 = v1345->regs;
  int v1349 = v1348[13];
  int v1350 = v1348[7];
  int v1358 = v1349 + v1350;
  v1348[13] = v1358;
  struct StateT * v1352 = slot_228(v1345);
  return v1352;
}

struct StateT * slot_169(struct StateT * v3848) {
  int v3849 = v3848->timer;
  int v3857 = v3849 + 1;
  v3848->timer = v3857;
  int * v3851 = v3848->regs;
  int v3852 = v3851[26];
  int v3853 = v3851[6];
  int v3861 = v3852 ^ v3853;
  v3851[26] = v3861;
  struct StateT * v3855 = slot_170(v3848);
  return v3855;
}

struct StateT * slot_253(struct StateT * v2186) {
  int v2187 = v2186->timer;
  int v2196 = v2187 + 1;
  v2186->timer = v2196;
  int * v2189 = v2186->regs;
  int v2190 = v2189[10];
  int v2191 = v2189[25];
  int * v2192 = v2186->mem;
  int v2201 = (int)((unsigned int)(v2190 + 28) >> 2);
  v2192[v2201] = v2191;
  struct StateT * v2194 = slot_254(v2186);
  return v2194;
}

struct StateT * slot_64(struct StateT * v1330) {
  int v1331 = v1330->timer;
  int v1338 = v1331 + 1;
  v1330->timer = v1338;
  int * v1333 = v1330->regs;
  int v1334 = v1333[8];
  int v1342 = (int)((unsigned int)v1334 >> 25);
  v1333[20] = v1342;
  struct StateT * v1336 = slot_65(v1330);
  return v1336;
}

struct StateT * slot_170(struct StateT * v3864) {
  int v3865 = v3864->timer;
  int v3873 = v3865 + 1;
  v3864->timer = v3873;
  int * v3867 = v3864->regs;
  int v3868 = v3867[24];
  int v3869 = v3867[8];
  int v3877 = v3868 ^ v3869;
  v3867[24] = v3877;
  struct StateT * v3871 = slot_171(v3864);
  return v3871;
}

struct StateT * slot_14(struct StateT * v263) {
  int v264 = v263->timer;
  int v270 = v264 + 1;
  v263->timer = v270;
  int * v266 = v263->regs;
  v266[30] = 0;
  struct StateT * v268 = slot_15(v263);
  return v268;
}

struct StateT * slot_53(struct StateT * v973) {
  int v974 = v973->timer;
  int v982 = v974 + 1;
  v973->timer = v982;
  int * v976 = v973->regs;
  int v977 = v976[19];
  int v978 = v976[5];
  int v987 = v977 + v978;
  v976[18] = v987;
  struct StateT * v980 = slot_54(v973);
  return v980;
}

struct StateT * slot_80(struct StateT * v1835) {
  int v1836 = v1835->timer;
  int v1844 = v1836 + 1;
  v1835->timer = v1844;
  int * v1838 = v1835->regs;
  int v1839 = v1838[8];
  int v1840 = v1838[20];
  int v1848 = v1839 | v1840;
  v1838[8] = v1848;
  struct StateT * v1842 = slot_81(v1835);
  return v1842;
}

struct StateT * slot_44(struct StateT * v780) {
  int v781 = v780->timer;
  int v788 = v781 + 1;
  v780->timer = v788;
  int * v783 = v780->regs;
  int v784 = v783[6];
  v783[12] = v784;
  struct StateT * v786 = slot_45(v780);
  return v786;
}

struct StateT * slot_261(struct StateT * v2466) {
  int v2467 = v2466->timer;
  int v2476 = v2467 + 1;
  v2466->timer = v2476;
  int * v2469 = v2466->regs;
  int v2470 = v2469[10];
  int v2471 = v2469[30];
  int * v2472 = v2466->mem;
  int v2481 = (int)((unsigned int)(v2470 + 60) >> 2);
  v2472[v2481] = v2471;
  struct StateT * v2474 = slot_262(v2466);
  return v2474;
}

struct StateT * slot_137(struct StateT * v3349) {
  int v3350 = v3349->timer;
  int v3358 = v3350 + 1;
  v3349->timer = v3358;
  int * v3352 = v3349->regs;
  int v3353 = v3352[15];
  int v3354 = v3352[5];
  int v3362 = v3353 | v3354;
  v3352[15] = v3362;
  struct StateT * v3356 = slot_138(v3349);
  return v3356;
}

struct StateT * slot_122(struct StateT * v3112) {
  int v3113 = v3112->timer;
  int v3120 = v3113 + 1;
  v3112->timer = v3120;
  int * v3115 = v3112->regs;
  int v3116 = v3115[17];
  int v3123 = v3116 << 18;
  v3115[17] = v3123;
  struct StateT * v3118 = slot_123(v3112);
  return v3118;
}

struct StateT * slot_99(struct StateT * v2485) {
  int v2486 = v2485->timer;
  int v2493 = v2486 + 1;
  v2485->timer = v2493;
  int * v2488 = v2485->regs;
  int v2489 = v2488[8];
  int v2496 = v2489 << 13;
  v2488[8] = v2496;
  struct StateT * v2491 = slot_100(v2485);
  return v2491;
}

struct StateT * slot_179(struct StateT * v4008) {
  int v4009 = v4008->timer;
  int v4016 = v4009 + 1;
  v4008->timer = v4016;
  int * v4011 = v4008->regs;
  int v4012 = v4011[15];
  int v4019 = v4012 << 13;
  v4011[15] = v4019;
  struct StateT * v4014 = slot_180(v4008);
  return v4014;
}

struct StateT * slot_219(struct StateT * v1087) {
  int v1088 = v1087->timer;
  int v1094 = v1088 + 1;
  v1087->timer = v1094;
  int * v1090 = v1087->regs;
  v1090[6] = 857759744;
  struct StateT * v1092 = slot_220(v1087);
  return v1092;
}

struct StateT * slot_36(struct StateT * v628) {
  int v629 = v628->timer;
  int v638 = v629 + 1;
  v628->timer = v638;
  int * v631 = v628->regs;
  int v632 = v631[2];
  int v633 = v631[26];
  int * v634 = v628->mem;
  int v643 = (int)((unsigned int)(v632 + 20) >> 2);
  v634[v643] = v633;
  struct StateT * v636 = slot_37(v628);
  return v636;
}

struct StateT * slot_57(struct StateT * v1100) {
  int v1101 = v1100->timer;
  int v1109 = v1101 + 1;
  v1100->timer = v1109;
  int * v1103 = v1100->regs;
  int v1104 = v1103[15];
  int v1105 = v1103[9];
  int v1113 = v1104 | v1105;
  v1103[15] = v1113;
  struct StateT * v1107 = slot_58(v1100);
  return v1107;
}

struct StateT * slot_62(struct StateT * v1265) {
  int v1266 = v1265->timer;
  int v1273 = v1266 + 1;
  v1265->timer = v1273;
  int * v1268 = v1265->regs;
  int v1269 = v1268[18];
  int v1276 = v1269 << 7;
  v1268[18] = v1276;
  struct StateT * v1271 = slot_63(v1265);
  return v1271;
}

struct StateT * slot_22(struct StateT * v409) {
  int v410 = v409->timer;
  int v419 = v410 + 1;
  v409->timer = v419;
  int * v412 = v409->regs;
  int v413 = v412[12];
  int * v414 = v409->mem;
  int v423 = (int)((unsigned int)(v413 + 28) >> 2);
  int v415 = v414[v423];
  v412[1] = v415;
  struct StateT * v417 = slot_23(v409);
  return v417;
}

struct StateT * slot_139(struct StateT * v3380) {
  int v3381 = v3380->timer;
  int v3388 = v3381 + 1;
  v3380->timer = v3388;
  int * v3383 = v3380->regs;
  int v3384 = v3383[11];
  int v3391 = v3384 << 7;
  v3383[11] = v3391;
  struct StateT * v3386 = slot_140(v3380);
  return v3386;
}

struct StateT * slot_221(struct StateT * v1150) {
  int v1151 = v1150->timer;
  int v1159 = v1151 + 1;
  v1150->timer = v1159;
  int * v1153 = v1150->regs;
  int v1154 = v1153[5];
  int v1155 = v1153[7];
  int v1163 = v1154 + v1155;
  v1153[5] = v1163;
  struct StateT * v1157 = slot_222(v1150);
  return v1157;
}

struct StateT * slot_23(struct StateT * v428) {
  int v429 = v428->timer;
  int v438 = v429 + 1;
  v428->timer = v438;
  int * v431 = v428->regs;
  int v432 = v431[11];
  int * v433 = v428->mem;
  int v442 = (int)((unsigned int)v432 >> 2);
  int v434 = v433[v442];
  v431[5] = v434;
  struct StateT * v436 = slot_24(v428);
  return v436;
}

struct StateT * slot_153(struct StateT * v3602) {
  int v3603 = v3602->timer;
  int v3611 = v3603 + 1;
  v3602->timer = v3611;
  int * v3605 = v3602->regs;
  int v3606 = v3605[17];
  int v3607 = v3605[19];
  int v3616 = v3606 + v3607;
  v3605[6] = v3616;
  struct StateT * v3609 = slot_154(v3602);
  return v3609;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v45 = v36 + 1;
  v35->timer = v45;
  int * v38 = v35->regs;
  int v39 = v38[2];
  int v40 = v38[8];
  int * v41 = v35->mem;
  int v50 = (int)((unsigned int)(v39 + 88) >> 2);
  v41[v50] = v40;
  struct StateT * v43 = slot_3(v35);
  return v43;
}

struct StateT * slot_86(struct StateT * v2030) {
  int v2031 = v2030->timer;
  int v2039 = v2031 + 1;
  v2030->timer = v2039;
  int * v2033 = v2030->regs;
  int v2034 = v2033[18];
  int v2035 = v2033[20];
  int v2043 = v2034 | v2035;
  v2033[18] = v2043;
  struct StateT * v2037 = slot_87(v2030);
  return v2037;
}

struct StateT * slot_129(struct StateT * v3220) {
  int v3221 = v3220->timer;
  int v3229 = v3221 + 1;
  v3220->timer = v3229;
  int * v3223 = v3220->regs;
  int v3224 = v3223[19];
  int v3225 = v3223[17];
  int v3233 = v3224 ^ v3225;
  v3223[19] = v3233;
  struct StateT * v3227 = slot_130(v3220);
  return v3227;
}

struct StateT * slot_158(struct StateT * v3681) {
  int v3682 = v3681->timer;
  int v3689 = v3682 + 1;
  v3681->timer = v3689;
  int * v3684 = v3681->regs;
  int v3685 = v3684[15];
  int v3693 = (int)((unsigned int)v3685 >> 23);
  v3684[9] = v3693;
  struct StateT * v3687 = slot_159(v3681);
  return v3687;
}

struct StateT * slot_100(struct StateT * v2518) {
  int v2519 = v2518->timer;
  int v2527 = v2519 + 1;
  v2518->timer = v2527;
  int * v2521 = v2518->regs;
  int v2522 = v2521[8];
  int v2523 = v2521[20];
  int v2531 = v2522 | v2523;
  v2521[8] = v2531;
  struct StateT * v2525 = slot_101(v2518);
  return v2525;
}

struct StateT * slot_271(struct StateT * v2810) {
  int v2811 = v2810->timer;
  int v2820 = v2811 + 1;
  v2810->timer = v2820;
  int * v2813 = v2810->regs;
  int v2814 = v2813[2];
  int * v2815 = v2810->mem;
  int v2824 = (int)((unsigned int)(v2814 + 56) >> 2);
  int v2816 = v2815[v2824];
  v2813[24] = v2816;
  struct StateT * v2818 = slot_272(v2810);
  return v2818;
}

struct StateT * slot_127(struct StateT * v3187) {
  int v3188 = v3187->timer;
  int v3196 = v3188 + 1;
  v3187->timer = v3196;
  int * v3190 = v3187->regs;
  int v3191 = v3190[21];
  int v3192 = v3190[15];
  int v3200 = v3191 ^ v3192;
  v3190[21] = v3200;
  struct StateT * v3194 = slot_128(v3187);
  return v3194;
}

struct StateT * slot_217(struct StateT * v1023) {
  int v1024 = v1023->timer;
  int v1033 = v1024 + 1;
  v1023->timer = v1033;
  int * v1026 = v1023->regs;
  int v1027 = v1026[2];
  int * v1028 = v1023->mem;
  int v1037 = (int)((unsigned int)(v1027 + 8) >> 2);
  int v1029 = v1028[v1037];
  v1026[6] = v1029;
  struct StateT * v1031 = slot_218(v1023);
  return v1031;
}

struct StateT * slot_13(struct StateT * v244) {
  int v245 = v244->timer;
  int v254 = v245 + 1;
  v244->timer = v254;
  int * v247 = v244->regs;
  int v248 = v247[2];
  int v249 = v247[27];
  int * v250 = v244->mem;
  int v259 = (int)((unsigned int)(v248 + 44) >> 2);
  v250[v259] = v249;
  struct StateT * v252 = slot_14(v244);
  return v252;
}

struct StateT * slot_111(struct StateT * v2901) {
  int v2902 = v2901->timer;
  int v2910 = v2902 + 1;
  v2901->timer = v2910;
  int * v2904 = v2901->regs;
  int v2905 = v2904[9];
  int v2906 = v2904[26];
  int v2915 = v2905 + v2906;
  v2904[15] = v2915;
  struct StateT * v2908 = slot_112(v2901);
  return v2908;
}

struct StateT * slot_109(struct StateT * v2829) {
  int v2830 = v2829->timer;
  int v2838 = v2830 + 1;
  v2829->timer = v2838;
  int * v2832 = v2829->regs;
  int v2833 = v2832[5];
  int v2834 = v2832[20];
  int v2843 = v2833 ^ v2834;
  v2832[18] = v2843;
  struct StateT * v2836 = slot_110(v2829);
  return v2836;
}

struct StateT * slot_174(struct StateT * v3931) {
  int v3932 = v3931->timer;
  int v3940 = v3932 + 1;
  v3931->timer = v3940;
  int * v3934 = v3931->regs;
  int v3935 = v3934[24];
  int v3936 = v3934[16];
  int v3945 = v3935 + v3936;
  v3934[8] = v3945;
  struct StateT * v3938 = slot_175(v3931);
  return v3938;
}

struct StateT * slot_147(struct StateT * v3501) {
  int v3502 = v3501->timer;
  int v3510 = v3502 + 1;
  v3501->timer = v3510;
  int * v3504 = v3501->regs;
  int v3505 = v3504[23];
  int v3506 = v3504[15];
  int v3514 = v3505 ^ v3506;
  v3504[23] = v3514;
  struct StateT * v3508 = slot_148(v3501);
  return v3508;
}

struct StateT * slot_42(struct StateT * v742) {
  int v743 = v742->timer;
  int v752 = v743 + 1;
  v742->timer = v752;
  int * v745 = v742->regs;
  int v746 = v745[2];
  int v747 = v745[17];
  int * v748 = v742->mem;
  int v757 = (int)((unsigned int)(v746 + 28) >> 2);
  v748[v757] = v747;
  struct StateT * v750 = slot_43(v742);
  return v750;
}

struct StateT * slot_224(struct StateT * v1246) {
  int v1247 = v1246->timer;
  int v1256 = v1247 + 1;
  v1246->timer = v1256;
  int * v1249 = v1246->regs;
  int v1250 = v1249[2];
  int * v1251 = v1246->mem;
  int v1260 = (int)((unsigned int)(v1250 + 20) >> 2);
  int v1252 = v1251[v1260];
  v1249[7] = v1252;
  struct StateT * v1254 = slot_225(v1246);
  return v1254;
}

struct StateT * slot_163(struct StateT * v3755) {
  int v3756 = v3755->timer;
  int v3764 = v3756 + 1;
  v3755->timer = v3764;
  int * v3758 = v3755->regs;
  int v3759 = v3758[6];
  int v3760 = v3758[9];
  int v3768 = v3759 | v3760;
  v3758[6] = v3768;
  struct StateT * v3762 = slot_164(v3755);
  return v3762;
}

struct StateT * slot_184(struct StateT * v4083) {
  int v4084 = v4083->timer;
  int v4091 = v4084 + 1;
  v4083->timer = v4091;
  int * v4086 = v4083->regs;
  int v4087 = v4086[8];
  int v4095 = (int)((unsigned int)v4087 >> 19);
  v4086[9] = v4095;
  struct StateT * v4089 = slot_185(v4083);
  return v4089;
}

struct StateT * slot_204(struct StateT * v4395) {
  int v4396 = v4395->timer;
  int v4403 = v4396 + 1;
  v4395->timer = v4403;
  int * v4398 = v4395->regs;
  int v4399 = v4398[8];
  int v4407 = (int)((unsigned int)v4399 >> 14);
  v4398[9] = v4407;
  struct StateT * v4401 = slot_205(v4395);
  return v4401;
}

struct StateT * slot_194(struct StateT * v4243) {
  int v4244 = v4243->timer;
  int v4252 = v4244 + 1;
  v4243->timer = v4252;
  int * v4246 = v4243->regs;
  int v4247 = v4246[1];
  int v4248 = v4246[24];
  int v4257 = v4247 + v4248;
  v4246[8] = v4257;
  struct StateT * v4250 = slot_195(v4243);
  return v4250;
}

struct StateT * slot_165(struct StateT * v3786) {
  int v3787 = v3786->timer;
  int v3794 = v3787 + 1;
  v3786->timer = v3794;
  int * v3789 = v3786->regs;
  int v3790 = v3789[8];
  int v3797 = v3790 << 9;
  v3789[8] = v3797;
  struct StateT * v3792 = slot_166(v3786);
  return v3792;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v2081) {
  int v2082 = v2081->timer;
  int v2091 = v2082 + 1;
  v2081->timer = v2091;
  int * v2084 = v2081->regs;
  int v2085 = v2084[10];
  int v2086 = v2084[12];
  int * v2087 = v2081->mem;
  int v2096 = (int)((unsigned int)(v2085 + 16) >> 2);
  v2087[v2096] = v2086;
  struct StateT * v2089 = slot_251(v2081);
  return v2089;
}

struct StateT * slot_259(struct StateT * v2397) {
  int v2398 = v2397->timer;
  int v2407 = v2398 + 1;
  v2397->timer = v2407;
  int * v2400 = v2397->regs;
  int v2401 = v2400[10];
  int v2402 = v2400[24];
  int * v2403 = v2397->mem;
  int v2412 = (int)((unsigned int)(v2401 + 52) >> 2);
  v2403[v2412] = v2402;
  struct StateT * v2405 = slot_260(v2397);
  return v2405;
}

struct StateT * slot_117(struct StateT * v3036) {
  int v3037 = v3036->timer;
  int v3045 = v3037 + 1;
  v3036->timer = v3045;
  int * v3039 = v3036->regs;
  int v3040 = v3039[15];
  int v3041 = v3039[6];
  int v3049 = v3040 | v3041;
  v3039[15] = v3049;
  struct StateT * v3043 = slot_118(v3036);
  return v3043;
}

struct StateT * slot_249(struct StateT * v2046) {
  int v2047 = v2046->timer;
  int v2056 = v2047 + 1;
  v2046->timer = v2056;
  int * v2049 = v2046->regs;
  int v2050 = v2049[10];
  int v2051 = v2049[14];
  int * v2052 = v2046->mem;
  int v2061 = (int)((unsigned int)(v2050 + 12) >> 2);
  v2052[v2061] = v2051;
  struct StateT * v2054 = slot_250(v2046);
  return v2054;
}

struct StateT * slot_90(struct StateT * v2170) {
  int v2171 = v2170->timer;
  int v2179 = v2171 + 1;
  v2170->timer = v2179;
  int * v2173 = v2170->regs;
  int v2174 = v2173[25];
  int v2175 = v2173[18];
  int v2183 = v2174 ^ v2175;
  v2173[25] = v2183;
  struct StateT * v2177 = slot_91(v2170);
  return v2177;
}

struct StateT * slot_11(struct StateT * v206) {
  int v207 = v206->timer;
  int v216 = v207 + 1;
  v206->timer = v216;
  int * v209 = v206->regs;
  int v210 = v209[2];
  int v211 = v209[25];
  int * v212 = v206->mem;
  int v221 = (int)((unsigned int)(v210 + 52) >> 2);
  v212[v221] = v211;
  struct StateT * v214 = slot_12(v206);
  return v214;
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
  
  // a10, 16 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 64;
  s2.regs[11] = 64;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[16 + i] = secret(0, 20);
    s2.mem[16 + i] = secret(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[20 + i] = secret(0, 20);
    s2.mem[20 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}