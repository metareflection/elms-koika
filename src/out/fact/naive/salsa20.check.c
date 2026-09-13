// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
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
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v249);
struct StateT * slot_228(struct StateT * v1549);
struct StateT * slot_143(struct StateT * v3969);
struct StateT * slot_120(struct StateT * v3539);
struct StateT * slot_226(struct StateT * v1475);
struct StateT * slot_167(struct StateT * v4422);
struct StateT * slot_268(struct StateT * v3097);
struct StateT * slot_152(struct StateT * v4147);
struct StateT * slot_231(struct StateT * v1663);
struct StateT * slot_199(struct StateT * v5032);
struct StateT * slot_252(struct StateT * v2465);
struct StateT * slot_92(struct StateT * v2569);
struct StateT * slot_232(struct StateT * v1704);
struct StateT * slot_269(struct StateT * v3139);
struct StateT * slot_31(struct StateT * v612);
struct StateT * slot_236(struct StateT * v1869);
struct StateT * slot_241(struct StateT * v2041);
struct StateT * slot_160(struct StateT * v4296);
struct StateT * slot_251(struct StateT * v2424);
struct StateT * slot_65(struct StateT * v1533);
struct StateT * slot_10(struct StateT * v207);
struct StateT * slot_150(struct StateT * v4105);
struct StateT * slot_74(struct StateT * v1889);
struct StateT * slot_262(struct StateT * v2865);
struct StateT * slot_107(struct StateT * v3160);
struct StateT * slot_136(struct StateT * v3847);
struct StateT * slot_84(struct StateT * v2247);
struct StateT * slot_28(struct StateT * v569);
struct StateT * slot_155(struct StateT * v4210);
struct StateT * slot_177(struct StateT * v4619);
struct StateT * slot_229(struct StateT * v1582);
struct StateT * slot_17(struct StateT * v346);
struct StateT * slot_181(struct StateT * v4692);
struct StateT * slot_197(struct StateT * v4995);
struct StateT * slot_207(struct StateT * v5174);
struct StateT * slot_156(struct StateT * v4227);
struct StateT * slot_154(struct StateT * v4189);
struct StateT * slot_68(struct StateT * v1643);
struct StateT * slot_260(struct StateT * v2790);
struct StateT * slot_105(struct StateT * v3081);
struct StateT * slot_27(struct StateT * v556);
struct StateT * slot_164(struct StateT * v4369);
struct StateT * slot_15(struct StateT * v304);
struct StateT * slot_133(struct StateT * v3788);
struct StateT * slot_56(struct StateT * v1197);
struct StateT * slot_244(struct StateT * v2150);
struct StateT * slot_222(struct StateT * v1320);
struct StateT * slot_34(struct StateT * v659);
struct StateT * slot_171(struct StateT * v4502);
struct StateT * slot_162(struct StateT * v4333);
struct StateT * slot_21(struct StateT * v430);
struct StateT * slot_239(struct StateT * v1972);
struct StateT * slot_118(struct StateT * v3506);
struct StateT * slot_121(struct StateT * v3559);
struct StateT * slot_144(struct StateT * v3989);
struct StateT * slot_267(struct StateT * v3060);
struct StateT * slot_201(struct StateT * v5068);
struct StateT * slot_94(struct StateT * v2653);
struct StateT * slot_63(struct StateT * v1455);
struct StateT * slot_146(struct StateT * v4022);
struct StateT * slot_24(struct StateT * v493);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v4962);
struct StateT * slot_125(struct StateT * v3629);
struct StateT * slot_254(struct StateT * v2548);
struct StateT * slot_148(struct StateT * v4063);
struct StateT * slot_126(struct StateT * v3645);
struct StateT * slot_223(struct StateT * v1361);
struct StateT * slot_79(struct StateT * v2057);
struct StateT * slot_237(struct StateT * v1910);
struct StateT * slot_41(struct StateT * v793);
struct StateT * slot_39(struct StateT * v751);
struct StateT * slot_142(struct StateT * v3953);
struct StateT * slot_60(struct StateT * v1341);
struct StateT * slot_238(struct StateT * v1940);
struct StateT * slot_112(struct StateT * v3369);
struct StateT * slot_256(struct StateT * v2632);
struct StateT * slot_272(struct StateT * v3264);
struct StateT * slot_47(struct StateT * v907);
struct StateT * slot_214(struct StateT * v1023);
struct StateT * slot_29(struct StateT * v582);
struct StateT * slot_16(struct StateT * v325);
struct StateT * slot_245(struct StateT * v2186);
struct StateT * slot_113(struct StateT * v3406);
struct StateT * slot_151(struct StateT * v4126);
struct StateT * slot_7(struct StateT * v144);
struct StateT * slot_124(struct StateT * v3612);
struct StateT * slot_191(struct StateT * v4878);
struct StateT * slot_103(struct StateT * v3002);
struct StateT * slot_128(struct StateT * v3685);
struct StateT * slot_19(struct StateT * v388);
struct StateT * slot_87(struct StateT * v2363);
struct StateT * slot_67(struct StateT * v1603);
struct StateT * slot_81(struct StateT * v2133);
struct StateT * slot_95(struct StateT * v2695);
struct StateT * slot_115(struct StateT * v3453);
struct StateT * slot_78(struct StateT * v2024);
struct StateT * slot_32(struct StateT * v629);
struct StateT * slot_205(struct StateT * v5138);
struct StateT * slot_193(struct StateT * v4920);
struct StateT * slot_233(struct StateT * v1744);
struct StateT * slot_176(struct StateT * v4603);
struct StateT * slot_189(struct StateT * v4838);
struct StateT * slot_33(struct StateT * v646);
struct StateT * slot_35(struct StateT * v675);
struct StateT * slot_258(struct StateT * v2712);
struct StateT * slot_246(struct StateT * v2226);
struct StateT * slot_210(struct StateT * v5235);
struct StateT * slot_166(struct StateT * v4402);
struct StateT * slot_51(struct StateT * v1002);
struct StateT * slot_52(struct StateT * v1043);
struct StateT * slot_83(struct StateT * v2206);
struct StateT * slot_25(struct StateT * v514);
struct StateT * slot_209(struct StateT * v5215);
struct StateT * slot_3(struct StateT * v60);
struct StateT * slot_264(struct StateT * v2944);
struct StateT * slot_123(struct StateT * v3592);
struct StateT * slot_73(struct StateT * v1848);
struct StateT * slot_270(struct StateT * v3181);
struct StateT * slot_198(struct StateT * v5015);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_187(struct StateT * v4798);
struct StateT * slot_97(struct StateT * v2770);
struct StateT * slot_182(struct StateT * v4709);
struct StateT * slot_38(struct StateT * v730);
struct StateT * slot_178(struct StateT * v4639);
struct StateT * slot_106(struct StateT * v3118);
struct StateT * slot_98(struct StateT * v2811);
struct StateT * slot_159(struct StateT * v4280);
struct StateT * slot_46(struct StateT * v890);
struct StateT * slot_212(struct StateT * v5271);
struct StateT * slot_132(struct StateT * v3767);
struct StateT * slot_130(struct StateT * v3726);
struct StateT * slot_211(struct StateT * v5255);
struct StateT * slot_20(struct StateT * v409);
struct StateT * slot_141(struct StateT * v3936);
struct StateT * slot_61(struct StateT * v1381);
struct StateT * slot_30(struct StateT * v595);
struct StateT * slot_4(struct StateT * v81);
struct StateT * slot_18(struct StateT * v367);
struct StateT * slot_9(struct StateT * v186);
struct StateT * slot_183(struct StateT * v4725);
struct StateT * slot_240(struct StateT * v2008);
struct StateT * slot_247(struct StateT * v2264);
struct StateT * slot_43(struct StateT * v835);
struct StateT * slot_70(struct StateT * v1724);
struct StateT * slot_168(struct StateT * v4442);
struct StateT * slot_76(struct StateT * v1956);
struct StateT * slot_6(struct StateT * v123);
struct StateT * slot_225(struct StateT * v1435);
struct StateT * slot_55(struct StateT * v1160);
struct StateT * slot_213(struct StateT * v982);
struct StateT * slot_82(struct StateT * v2170);
struct StateT * slot_274(struct StateT * v3348);
struct StateT * slot_263(struct StateT * v2906);
struct StateT * slot_161(struct StateT * v4316);
struct StateT * slot_185(struct StateT * v4762);
struct StateT * slot_91(struct StateT * v2527);
struct StateT * slot_58(struct StateT * v1267);
struct StateT * slot_89(struct StateT * v2445);
struct StateT * slot_255(struct StateT * v2590);
struct StateT * slot_66(struct StateT * v1562);
struct StateT * slot_140(struct StateT * v3916);
struct StateT * slot_265(struct StateT * v2981);
struct StateT * slot_49(struct StateT * v945);
struct StateT * slot_216(struct StateT * v1098);
struct StateT * slot_50(struct StateT * v962);
struct StateT * slot_37(struct StateT * v709);
struct StateT * slot_114(struct StateT * v3432);
struct StateT * slot_135(struct StateT * v3830);
struct StateT * slot_248(struct StateT * v2301);
struct StateT * slot_257(struct StateT * v2674);
struct StateT * slot_59(struct StateT * v1304);
struct StateT * slot_192(struct StateT * v4899);
struct StateT * slot_40(struct StateT * v772);
struct StateT * slot_48(struct StateT * v924);
struct StateT * slot_77(struct StateT * v1988);
struct StateT * slot_85(struct StateT * v2285);
struct StateT * slot_75(struct StateT * v1923);
struct StateT * slot_72(struct StateT * v1806);
struct StateT * slot_119(struct StateT * v3523);
struct StateT * slot_71(struct StateT * v1765);
struct StateT * slot_101(struct StateT * v2927);
struct StateT * slot_276(struct StateT * v3427);
struct StateT * slot_108(struct StateT * v3202);
struct StateT * slot_116(struct StateT * v3470);
struct StateT * slot_93(struct StateT * v2611);
struct StateT * slot_266(struct StateT * v3022);
struct StateT * slot_88(struct StateT * v2404);
struct StateT * slot_96(struct StateT * v2733);
struct StateT * slot_215(struct StateT * v1064);
struct StateT * slot_234(struct StateT * v1786);
struct StateT * slot_45(struct StateT * v873);
struct StateT * slot_218(struct StateT * v1177);
struct StateT * slot_220(struct StateT * v1246);
struct StateT * slot_134(struct StateT * v3809);
struct StateT * slot_175(struct StateT * v4586);
struct StateT * slot_273(struct StateT * v3306);
struct StateT * slot_69(struct StateT * v1684);
struct StateT * slot_202(struct StateT * v5085);
struct StateT * slot_230(struct StateT * v1623);
struct StateT * slot_188(struct StateT * v4818);
struct StateT * slot_138(struct StateT * v3883);
struct StateT * slot_186(struct StateT * v4778);
struct StateT * slot_102(struct StateT * v2965);
struct StateT * slot_145(struct StateT * v4006);
struct StateT * slot_110(struct StateT * v3285);
struct StateT * slot_196(struct StateT * v4979);
struct StateT * slot_208(struct StateT * v5194);
struct StateT * slot_172(struct StateT * v4523);
struct StateT * slot_131(struct StateT * v3746);
struct StateT * slot_8(struct StateT * v165);
struct StateT * slot_180(struct StateT * v4672);
struct StateT * slot_203(struct StateT * v5101);
struct StateT * slot_190(struct StateT * v4858);
struct StateT * slot_157(struct StateT * v4243);
struct StateT * slot_242(struct StateT * v2073);
struct StateT * slot_200(struct StateT * v5048);
struct StateT * slot_243(struct StateT * v2113);
struct StateT * slot_173(struct StateT * v4544);
struct StateT * slot_149(struct StateT * v4084);
struct StateT * slot_5(struct StateT * v102);
struct StateT * slot_104(struct StateT * v3043);
struct StateT * slot_235(struct StateT * v1827);
struct StateT * slot_275(struct StateT * v3390);
struct StateT * slot_54(struct StateT * v1118);
struct StateT * slot_26(struct StateT * v535);
struct StateT * slot_206(struct StateT * v5154);
struct StateT * slot_227(struct StateT * v1513);
struct StateT * slot_169(struct StateT * v4462);
struct StateT * slot_253(struct StateT * v2506);
struct StateT * slot_64(struct StateT * v1496);
struct StateT * slot_170(struct StateT * v4482);
struct StateT * slot_14(struct StateT * v291);
struct StateT * slot_53(struct StateT * v1077);
struct StateT * slot_80(struct StateT * v2093);
struct StateT * slot_44(struct StateT * v856);
struct StateT * slot_261(struct StateT * v2828);
struct StateT * slot_137(struct StateT * v3863);
struct StateT * slot_122(struct StateT * v3576);
struct StateT * slot_99(struct StateT * v2849);
struct StateT * slot_179(struct StateT * v4656);
struct StateT * slot_219(struct StateT * v1213);
struct StateT * slot_36(struct StateT * v688);
struct StateT * slot_57(struct StateT * v1226);
struct StateT * slot_62(struct StateT * v1419);
struct StateT * slot_22(struct StateT * v451);
struct StateT * slot_139(struct StateT * v3900);
struct StateT * slot_221(struct StateT * v1284);
struct StateT * slot_23(struct StateT * v472);
struct StateT * slot_153(struct StateT * v4168);
struct StateT * slot_2(struct StateT * v39);
struct StateT * slot_86(struct StateT * v2322);
struct StateT * slot_129(struct StateT * v3706);
struct StateT * slot_158(struct StateT * v4263);
struct StateT * slot_100(struct StateT * v2886);
struct StateT * slot_271(struct StateT * v3222);
struct StateT * slot_127(struct StateT * v3665);
struct StateT * slot_217(struct StateT * v1139);
struct StateT * slot_13(struct StateT * v270);
struct StateT * slot_111(struct StateT * v3327);
struct StateT * slot_109(struct StateT * v3243);
struct StateT * slot_174(struct StateT * v4565);
struct StateT * slot_147(struct StateT * v4043);
struct StateT * slot_42(struct StateT * v814);
struct StateT * slot_224(struct StateT * v1398);
struct StateT * slot_163(struct StateT * v4349);
struct StateT * slot_184(struct StateT * v4745);
struct StateT * slot_204(struct StateT * v5121);
struct StateT * slot_194(struct StateT * v4941);
struct StateT * slot_165(struct StateT * v4386);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v2383);
struct StateT * slot_259(struct StateT * v2749);
struct StateT * slot_117(struct StateT * v3486);
struct StateT * slot_249(struct StateT * v2342);
struct StateT * slot_90(struct StateT * v2486);
struct StateT * slot_11(struct StateT * v228);
struct StateT * slot_12(struct StateT * v249) {
  int v250 = v249->timer;
  int v260 = v250 + 1;
  v249->timer = v260;
  int * v252 = v249->regs;
  int v253 = v252[2];
  int * v254 = v249->regs;
  int v255 = v254[26];
  int * v256 = v249->mem;
  int v266 = (int)((unsigned int)(v253 + 48) >> 2);
  v256[v266] = v255;
  struct StateT * v258 = slot_13(v249);
  return v258;
}

struct StateT * slot_228(struct StateT * v1549) {
  int v1550 = v1549->timer;
  int v1556 = v1550 + 1;
  v1549->timer = v1556;
  int * v1552 = v1549->regs;
  v1552[7] = 2036477952;
  struct StateT * v1554 = slot_229(v1549);
  return v1554;
}

struct StateT * slot_143(struct StateT * v3969) {
  int v3970 = v3969->timer;
  int v3980 = v3970 + 1;
  v3969->timer = v3980;
  int * v3972 = v3969->regs;
  int v3973 = v3972[16];
  int * v3974 = v3969->regs;
  int v3975 = v3974[5];
  int * v3976 = v3969->regs;
  int v3986 = v3973 | v3975;
  v3976[16] = v3986;
  struct StateT * v3978 = slot_144(v3969);
  return v3978;
}

struct StateT * slot_120(struct StateT * v3539) {
  int v3540 = v3539->timer;
  int v3550 = v3540 + 1;
  v3539->timer = v3550;
  int * v3542 = v3539->regs;
  int v3543 = v3542[16];
  int * v3544 = v3539->regs;
  int v3545 = v3544[6];
  int * v3546 = v3539->regs;
  int v3556 = v3543 | v3545;
  v3546[16] = v3556;
  struct StateT * v3548 = slot_121(v3539);
  return v3548;
}

struct StateT * slot_226(struct StateT * v1475) {
  int v1476 = v1475->timer;
  int v1486 = v1476 + 1;
  v1475->timer = v1486;
  int * v1478 = v1475->regs;
  int v1479 = v1478[2];
  int * v1480 = v1475->mem;
  int v1490 = (int)((unsigned int)(v1479 + 24) >> 2);
  int v1481 = v1480[v1490];
  int * v1482 = v1475->regs;
  v1482[7] = v1481;
  struct StateT * v1484 = slot_227(v1475);
  return v1484;
}

struct StateT * slot_167(struct StateT * v4422) {
  int v4423 = v4422->timer;
  int v4433 = v4423 + 1;
  v4422->timer = v4433;
  int * v4425 = v4422->regs;
  int v4426 = v4425[27];
  int * v4427 = v4422->regs;
  int v4428 = v4427[11];
  int * v4429 = v4422->regs;
  int v4439 = v4426 ^ v4428;
  v4429[27] = v4439;
  struct StateT * v4431 = slot_168(v4422);
  return v4431;
}

struct StateT * slot_268(struct StateT * v3097) {
  int v3098 = v3097->timer;
  int v3108 = v3098 + 1;
  v3097->timer = v3108;
  int * v3100 = v3097->regs;
  int v3101 = v3100[2];
  int * v3102 = v3097->mem;
  int v3112 = (int)((unsigned int)(v3101 + 68) >> 2);
  int v3103 = v3102[v3112];
  int * v3104 = v3097->regs;
  v3104[21] = v3103;
  struct StateT * v3106 = slot_269(v3097);
  return v3106;
}

struct StateT * slot_152(struct StateT * v4147) {
  int v4148 = v4147->timer;
  int v4158 = v4148 + 1;
  v4147->timer = v4158;
  int * v4150 = v4147->regs;
  int v4151 = v4150[5];
  int * v4152 = v4147->regs;
  int v4153 = v4152[20];
  int * v4154 = v4147->regs;
  int v4165 = v4151 + v4153;
  v4154[15] = v4165;
  struct StateT * v4156 = slot_153(v4147);
  return v4156;
}

struct StateT * slot_231(struct StateT * v1663) {
  int v1664 = v1663->timer;
  int v1674 = v1664 + 1;
  v1663->timer = v1674;
  int * v1666 = v1663->regs;
  int v1667 = v1666[2];
  int * v1668 = v1663->mem;
  int v1678 = (int)((unsigned int)(v1667 + 32) >> 2);
  int v1669 = v1668[v1678];
  int * v1670 = v1663->regs;
  v1670[30] = v1669;
  struct StateT * v1672 = slot_232(v1663);
  return v1672;
}

struct StateT * slot_199(struct StateT * v5032) {
  int v5033 = v5032->timer;
  int v5041 = v5033 + 1;
  v5032->timer = v5041;
  int * v5035 = v5032->regs;
  int v5036 = v5035[15];
  int * v5037 = v5032->regs;
  int v5045 = v5036 << 18;
  v5037[15] = v5045;
  struct StateT * v5039 = slot_200(v5032);
  return v5039;
}

struct StateT * slot_252(struct StateT * v2465) {
  int v2466 = v2465->timer;
  int v2476 = v2466 + 1;
  v2465->timer = v2476;
  int * v2468 = v2465->regs;
  int v2469 = v2468[10];
  int * v2470 = v2465->regs;
  int v2471 = v2470[5];
  int * v2472 = v2465->mem;
  int v2482 = (int)((unsigned int)(v2469 + 24) >> 2);
  v2472[v2482] = v2471;
  struct StateT * v2474 = slot_253(v2465);
  return v2474;
}

struct StateT * slot_92(struct StateT * v2569) {
  int v2570 = v2569->timer;
  int v2580 = v2570 + 1;
  v2569->timer = v2580;
  int * v2572 = v2569->regs;
  int v2573 = v2572[24];
  int * v2574 = v2569->regs;
  int v2575 = v2574[13];
  int * v2576 = v2569->regs;
  int v2587 = v2573 + v2575;
  v2576[8] = v2587;
  struct StateT * v2578 = slot_93(v2569);
  return v2578;
}

struct StateT * slot_232(struct StateT * v1704) {
  int v1705 = v1704->timer;
  int v1715 = v1705 + 1;
  v1704->timer = v1715;
  int * v1707 = v1704->regs;
  int v1708 = v1707[16];
  int * v1709 = v1704->regs;
  int v1710 = v1709[30];
  int * v1711 = v1704->regs;
  int v1721 = v1708 + v1710;
  v1711[16] = v1721;
  struct StateT * v1713 = slot_233(v1704);
  return v1713;
}

struct StateT * slot_269(struct StateT * v3139) {
  int v3140 = v3139->timer;
  int v3150 = v3140 + 1;
  v3139->timer = v3150;
  int * v3142 = v3139->regs;
  int v3143 = v3142[2];
  int * v3144 = v3139->mem;
  int v3154 = (int)((unsigned int)(v3143 + 64) >> 2);
  int v3145 = v3144[v3154];
  int * v3146 = v3139->regs;
  v3146[22] = v3145;
  struct StateT * v3148 = slot_270(v3139);
  return v3148;
}

struct StateT * slot_31(struct StateT * v612) {
  int v613 = v612->timer;
  int v621 = v613 + 1;
  v612->timer = v621;
  int * v615 = v612->regs;
  int v616 = v615[13];
  int * v617 = v612->regs;
  int v626 = v616 + 1134;
  v617[11] = v626;
  struct StateT * v619 = slot_32(v612);
  return v619;
}

struct StateT * slot_236(struct StateT * v1869) {
  int v1870 = v1869->timer;
  int v1880 = v1870 + 1;
  v1869->timer = v1880;
  int * v1872 = v1869->regs;
  int v1873 = v1872[1];
  int * v1874 = v1869->regs;
  int v1875 = v1874[30];
  int * v1876 = v1869->regs;
  int v1886 = v1873 + v1875;
  v1876[1] = v1886;
  struct StateT * v1878 = slot_237(v1869);
  return v1878;
}

struct StateT * slot_241(struct StateT * v2041) {
  int v2042 = v2041->timer;
  int v2050 = v2042 + 1;
  v2041->timer = v2050;
  int * v2044 = v2041->regs;
  int v2045 = v2044[30];
  int * v2046 = v2041->regs;
  int v2054 = v2045 + 1396;
  v2046[30] = v2054;
  struct StateT * v2048 = slot_242(v2041);
  return v2048;
}

struct StateT * slot_160(struct StateT * v4296) {
  int v4297 = v4296->timer;
  int v4307 = v4297 + 1;
  v4296->timer = v4307;
  int * v4299 = v4296->regs;
  int v4300 = v4299[15];
  int * v4301 = v4296->regs;
  int v4302 = v4301[9];
  int * v4303 = v4296->regs;
  int v4313 = v4300 | v4302;
  v4303[15] = v4313;
  struct StateT * v4305 = slot_161(v4296);
  return v4305;
}

struct StateT * slot_251(struct StateT * v2424) {
  int v2425 = v2424->timer;
  int v2435 = v2425 + 1;
  v2424->timer = v2435;
  int * v2427 = v2424->regs;
  int v2428 = v2427[10];
  int * v2429 = v2424->regs;
  int v2430 = v2429[11];
  int * v2431 = v2424->mem;
  int v2441 = (int)((unsigned int)(v2428 + 20) >> 2);
  v2431[v2441] = v2430;
  struct StateT * v2433 = slot_252(v2424);
  return v2433;
}

struct StateT * slot_65(struct StateT * v1533) {
  int v1534 = v1533->timer;
  int v1542 = v1534 + 1;
  v1533->timer = v1542;
  int * v1536 = v1533->regs;
  int v1537 = v1536[8];
  int * v1538 = v1533->regs;
  int v1546 = v1537 << 7;
  v1538[8] = v1546;
  struct StateT * v1540 = slot_66(v1533);
  return v1540;
}

struct StateT * slot_10(struct StateT * v207) {
  int v208 = v207->timer;
  int v218 = v208 + 1;
  v207->timer = v218;
  int * v210 = v207->regs;
  int v211 = v210[2];
  int * v212 = v207->regs;
  int v213 = v212[24];
  int * v214 = v207->mem;
  int v224 = (int)((unsigned int)(v211 + 56) >> 2);
  v214[v224] = v213;
  struct StateT * v216 = slot_11(v207);
  return v216;
}

struct StateT * slot_150(struct StateT * v4105) {
  int v4106 = v4105->timer;
  int v4116 = v4106 + 1;
  v4105->timer = v4116;
  int * v4108 = v4105->regs;
  int v4109 = v4108[9];
  int * v4110 = v4105->regs;
  int v4111 = v4110[6];
  int * v4112 = v4105->regs;
  int v4123 = v4109 ^ v4111;
  v4112[16] = v4123;
  struct StateT * v4114 = slot_151(v4105);
  return v4114;
}

struct StateT * slot_74(struct StateT * v1889) {
  int v1890 = v1889->timer;
  int v1900 = v1890 + 1;
  v1889->timer = v1900;
  int * v1892 = v1889->regs;
  int v1893 = v1892[14];
  int * v1894 = v1889->regs;
  int v1895 = v1894[22];
  int * v1896 = v1889->regs;
  int v1907 = v1893 + v1895;
  v1896[18] = v1907;
  struct StateT * v1898 = slot_75(v1889);
  return v1898;
}

struct StateT * slot_262(struct StateT * v2865) {
  int v2866 = v2865->timer;
  int v2876 = v2866 + 1;
  v2865->timer = v2876;
  int * v2868 = v2865->regs;
  int v2869 = v2868[2];
  int * v2870 = v2865->mem;
  int v2880 = (int)((unsigned int)(v2869 + 92) >> 2);
  int v2871 = v2870[v2880];
  int * v2872 = v2865->regs;
  v2872[1] = v2871;
  struct StateT * v2874 = slot_263(v2865);
  return v2874;
}

struct StateT * slot_107(struct StateT * v3160) {
  int v3161 = v3160->timer;
  int v3171 = v3161 + 1;
  v3160->timer = v3171;
  int * v3163 = v3160->regs;
  int v3164 = v3163[16];
  int * v3165 = v3160->regs;
  int v3166 = v3165[15];
  int * v3167 = v3160->regs;
  int v3178 = v3164 ^ v3166;
  v3167[9] = v3178;
  struct StateT * v3169 = slot_108(v3160);
  return v3169;
}

struct StateT * slot_136(struct StateT * v3847) {
  int v3848 = v3847->timer;
  int v3856 = v3848 + 1;
  v3847->timer = v3856;
  int * v3850 = v3847->regs;
  int v3851 = v3850[15];
  int * v3852 = v3847->regs;
  int v3860 = v3851 << 7;
  v3852[15] = v3860;
  struct StateT * v3854 = slot_137(v3847);
  return v3854;
}

struct StateT * slot_84(struct StateT * v2247) {
  int v2248 = v2247->timer;
  int v2256 = v2248 + 1;
  v2247->timer = v2256;
  int * v2250 = v2247->regs;
  int v2251 = v2250[18];
  int * v2252 = v2247->regs;
  int v2261 = (int)((unsigned int)v2251 >> 23);
  v2252[20] = v2261;
  struct StateT * v2254 = slot_85(v2247);
  return v2254;
}

struct StateT * slot_28(struct StateT * v569) {
  int v570 = v569->timer;
  int v576 = v570 + 1;
  v569->timer = v576;
  int * v572 = v569->regs;
  v572[13] = 857759744;
  struct StateT * v574 = slot_29(v569);
  return v574;
}

struct StateT * slot_155(struct StateT * v4210) {
  int v4211 = v4210->timer;
  int v4219 = v4211 + 1;
  v4210->timer = v4219;
  int * v4213 = v4210->regs;
  int v4214 = v4213[11];
  int * v4215 = v4210->regs;
  int v4224 = (int)((unsigned int)v4214 >> 23);
  v4215[9] = v4224;
  struct StateT * v4217 = slot_156(v4210);
  return v4217;
}

struct StateT * slot_177(struct StateT * v4619) {
  int v4620 = v4619->timer;
  int v4630 = v4620 + 1;
  v4619->timer = v4630;
  int * v4622 = v4619->regs;
  int v4623 = v4622[11];
  int * v4624 = v4619->regs;
  int v4625 = v4624[9];
  int * v4626 = v4619->regs;
  int v4636 = v4623 | v4625;
  v4626[11] = v4636;
  struct StateT * v4628 = slot_178(v4619);
  return v4628;
}

struct StateT * slot_229(struct StateT * v1582) {
  int v1583 = v1582->timer;
  int v1593 = v1583 + 1;
  v1582->timer = v1593;
  int * v1585 = v1582->regs;
  int v1586 = v1585[2];
  int * v1587 = v1582->mem;
  int v1597 = (int)((unsigned int)(v1586 + 28) >> 2);
  int v1588 = v1587[v1597];
  int * v1589 = v1582->regs;
  v1589[30] = v1588;
  struct StateT * v1591 = slot_230(v1582);
  return v1591;
}

struct StateT * slot_17(struct StateT * v346) {
  int v347 = v346->timer;
  int v357 = v347 + 1;
  v346->timer = v357;
  int * v349 = v346->regs;
  int v350 = v349[12];
  int * v351 = v346->mem;
  int v361 = (int)((unsigned int)(v350 + 8) >> 2);
  int v352 = v351[v361];
  int * v353 = v346->regs;
  v353[7] = v352;
  struct StateT * v355 = slot_18(v346);
  return v355;
}

struct StateT * slot_181(struct StateT * v4692) {
  int v4693 = v4692->timer;
  int v4701 = v4693 + 1;
  v4692->timer = v4701;
  int * v4695 = v4692->regs;
  int v4696 = v4695[6];
  int * v4697 = v4692->regs;
  int v4706 = (int)((unsigned int)v4696 >> 19);
  v4697[9] = v4706;
  struct StateT * v4699 = slot_182(v4692);
  return v4699;
}

struct StateT * slot_197(struct StateT * v4995) {
  int v4996 = v4995->timer;
  int v5006 = v4996 + 1;
  v4995->timer = v5006;
  int * v4998 = v4995->regs;
  int v4999 = v4998[11];
  int * v5000 = v4995->regs;
  int v5001 = v5000[9];
  int * v5002 = v4995->regs;
  int v5012 = v4999 | v5001;
  v5002[11] = v5012;
  struct StateT * v5004 = slot_198(v4995);
  return v5004;
}

struct StateT * slot_207(struct StateT * v5174) {
  int v5175 = v5174->timer;
  int v5185 = v5175 + 1;
  v5174->timer = v5185;
  int * v5177 = v5174->regs;
  int v5178 = v5177[21];
  int * v5179 = v5174->regs;
  int v5180 = v5179[11];
  int * v5181 = v5174->regs;
  int v5191 = v5178 ^ v5180;
  v5181[21] = v5191;
  struct StateT * v5183 = slot_208(v5174);
  return v5183;
}

struct StateT * slot_156(struct StateT * v4227) {
  int v4228 = v4227->timer;
  int v4236 = v4228 + 1;
  v4227->timer = v4236;
  int * v4230 = v4227->regs;
  int v4231 = v4230[11];
  int * v4232 = v4227->regs;
  int v4240 = v4231 << 9;
  v4232[11] = v4240;
  struct StateT * v4234 = slot_157(v4227);
  return v4234;
}

struct StateT * slot_154(struct StateT * v4189) {
  int v4190 = v4189->timer;
  int v4200 = v4190 + 1;
  v4189->timer = v4200;
  int * v4192 = v4189->regs;
  int v4193 = v4192[16];
  int * v4194 = v4189->regs;
  int v4195 = v4194[22];
  int * v4196 = v4189->regs;
  int v4207 = v4193 + v4195;
  v4196[8] = v4207;
  struct StateT * v4198 = slot_155(v4189);
  return v4198;
}

struct StateT * slot_68(struct StateT * v1643) {
  int v1644 = v1643->timer;
  int v1654 = v1644 + 1;
  v1643->timer = v1654;
  int * v1646 = v1643->regs;
  int v1647 = v1646[13];
  int * v1648 = v1643->regs;
  int v1649 = v1648[9];
  int * v1650 = v1643->regs;
  int v1660 = v1647 ^ v1649;
  v1650[13] = v1660;
  struct StateT * v1652 = slot_69(v1643);
  return v1652;
}

struct StateT * slot_260(struct StateT * v2790) {
  int v2791 = v2790->timer;
  int v2801 = v2791 + 1;
  v2790->timer = v2801;
  int * v2793 = v2790->regs;
  int v2794 = v2793[10];
  int * v2795 = v2790->regs;
  int v2796 = v2795[1];
  int * v2797 = v2790->mem;
  int v2807 = (int)((unsigned int)(v2794 + 56) >> 2);
  v2797[v2807] = v2796;
  struct StateT * v2799 = slot_261(v2790);
  return v2799;
}

struct StateT * slot_105(struct StateT * v3081) {
  int v3082 = v3081->timer;
  int v3090 = v3082 + 1;
  v3081->timer = v3090;
  int * v3084 = v3081->regs;
  int v3085 = v3084[18];
  int * v3086 = v3081->regs;
  int v3094 = v3085 << 13;
  v3086[18] = v3094;
  struct StateT * v3088 = slot_106(v3081);
  return v3088;
}

struct StateT * slot_27(struct StateT * v556) {
  int v557 = v556->timer;
  int v563 = v557 + 1;
  v556->timer = v563;
  int * v559 = v556->regs;
  v559[12] = 1634762752;
  struct StateT * v561 = slot_28(v556);
  return v561;
}

struct StateT * slot_164(struct StateT * v4369) {
  int v4370 = v4369->timer;
  int v4378 = v4370 + 1;
  v4369->timer = v4378;
  int * v4372 = v4369->regs;
  int v4373 = v4372[8];
  int * v4374 = v4369->regs;
  int v4383 = (int)((unsigned int)v4373 >> 23);
  v4374[9] = v4383;
  struct StateT * v4376 = slot_165(v4369);
  return v4376;
}

struct StateT * slot_15(struct StateT * v304) {
  int v305 = v304->timer;
  int v315 = v305 + 1;
  v304->timer = v315;
  int * v307 = v304->regs;
  int v308 = v307[12];
  int * v309 = v304->mem;
  int v319 = (int)((unsigned int)v308 >> 2);
  int v310 = v309[v319];
  int * v311 = v304->regs;
  v311[29] = v310;
  struct StateT * v313 = slot_16(v304);
  return v313;
}

struct StateT * slot_133(struct StateT * v3788) {
  int v3789 = v3788->timer;
  int v3799 = v3789 + 1;
  v3788->timer = v3799;
  int * v3791 = v3788->regs;
  int v3792 = v3791[19];
  int * v3793 = v3788->regs;
  int v3794 = v3793[13];
  int * v3795 = v3788->regs;
  int v3806 = v3792 + v3794;
  v3795[16] = v3806;
  struct StateT * v3797 = slot_134(v3788);
  return v3797;
}

struct StateT * slot_56(struct StateT * v1197) {
  int v1198 = v1197->timer;
  int v1206 = v1198 + 1;
  v1197->timer = v1206;
  int * v1200 = v1197->regs;
  int v1201 = v1200[15];
  int * v1202 = v1197->regs;
  int v1210 = v1201 << 7;
  v1202[15] = v1210;
  struct StateT * v1204 = slot_57(v1197);
  return v1204;
}

struct StateT * slot_244(struct StateT * v2150) {
  int v2151 = v2150->timer;
  int v2161 = v2151 + 1;
  v2150->timer = v2161;
  int * v2153 = v2150->regs;
  int v2154 = v2153[19];
  int * v2155 = v2150->regs;
  int v2156 = v2155[7];
  int * v2157 = v2150->regs;
  int v2167 = v2154 + v2156;
  v2157[7] = v2167;
  struct StateT * v2159 = slot_245(v2150);
  return v2159;
}

struct StateT * slot_222(struct StateT * v1320) {
  int v1321 = v1320->timer;
  int v1331 = v1321 + 1;
  v1320->timer = v1331;
  int * v1323 = v1320->regs;
  int v1324 = v1323[2];
  int * v1325 = v1320->mem;
  int v1335 = (int)((unsigned int)(v1324 + 16) >> 2);
  int v1326 = v1325[v1335];
  int * v1327 = v1320->regs;
  v1327[7] = v1326;
  struct StateT * v1329 = slot_223(v1320);
  return v1329;
}

struct StateT * slot_34(struct StateT * v659) {
  int v660 = v659->timer;
  int v668 = v660 + 1;
  v659->timer = v668;
  int * v662 = v659->regs;
  int v663 = v662[22];
  int * v664 = v659->regs;
  int v672 = v663 + 1396;
  v664[22] = v672;
  struct StateT * v666 = slot_35(v659);
  return v666;
}

struct StateT * slot_171(struct StateT * v4502) {
  int v4503 = v4502->timer;
  int v4513 = v4503 + 1;
  v4502->timer = v4513;
  int * v4505 = v4502->regs;
  int v4506 = v4505[27];
  int * v4507 = v4502->regs;
  int v4508 = v4507[23];
  int * v4509 = v4502->regs;
  int v4520 = v4506 + v4508;
  v4509[11] = v4520;
  struct StateT * v4511 = slot_172(v4502);
  return v4511;
}

struct StateT * slot_162(struct StateT * v4333) {
  int v4334 = v4333->timer;
  int v4342 = v4334 + 1;
  v4333->timer = v4342;
  int * v4336 = v4333->regs;
  int v4337 = v4336[6];
  int * v4338 = v4333->regs;
  int v4346 = v4337 << 9;
  v4338[6] = v4346;
  struct StateT * v4340 = slot_163(v4333);
  return v4340;
}

struct StateT * slot_21(struct StateT * v430) {
  int v431 = v430->timer;
  int v441 = v431 + 1;
  v430->timer = v441;
  int * v433 = v430->regs;
  int v434 = v433[12];
  int * v435 = v430->mem;
  int v445 = (int)((unsigned int)(v434 + 24) >> 2);
  int v436 = v435[v445];
  int * v437 = v430->regs;
  v437[24] = v436;
  struct StateT * v439 = slot_22(v430);
  return v439;
}

struct StateT * slot_239(struct StateT * v1972) {
  int v1973 = v1972->timer;
  int v1981 = v1973 + 1;
  v1972->timer = v1981;
  int * v1975 = v1972->regs;
  int v1976 = v1975[6];
  int * v1977 = v1972->regs;
  int v1985 = v1976 + 1134;
  v1977[6] = v1985;
  struct StateT * v1979 = slot_240(v1972);
  return v1979;
}

struct StateT * slot_118(struct StateT * v3506) {
  int v3507 = v3506->timer;
  int v3515 = v3507 + 1;
  v3506->timer = v3515;
  int * v3509 = v3506->regs;
  int v3510 = v3509[16];
  int * v3511 = v3506->regs;
  int v3520 = (int)((unsigned int)v3510 >> 14);
  v3511[6] = v3520;
  struct StateT * v3513 = slot_119(v3506);
  return v3513;
}

struct StateT * slot_121(struct StateT * v3559) {
  int v3560 = v3559->timer;
  int v3568 = v3560 + 1;
  v3559->timer = v3568;
  int * v3562 = v3559->regs;
  int v3563 = v3562[17];
  int * v3564 = v3559->regs;
  int v3573 = (int)((unsigned int)v3563 >> 14);
  v3564[6] = v3573;
  struct StateT * v3566 = slot_122(v3559);
  return v3566;
}

struct StateT * slot_144(struct StateT * v3989) {
  int v3990 = v3989->timer;
  int v3998 = v3990 + 1;
  v3989->timer = v3998;
  int * v3992 = v3989->regs;
  int v3993 = v3992[17];
  int * v3994 = v3989->regs;
  int v4003 = (int)((unsigned int)v3993 >> 25);
  v3994[5] = v4003;
  struct StateT * v3996 = slot_145(v3989);
  return v3996;
}

struct StateT * slot_267(struct StateT * v3060) {
  int v3061 = v3060->timer;
  int v3071 = v3061 + 1;
  v3060->timer = v3071;
  int * v3063 = v3060->regs;
  int v3064 = v3063[2];
  int * v3065 = v3060->mem;
  int v3075 = (int)((unsigned int)(v3064 + 72) >> 2);
  int v3066 = v3065[v3075];
  int * v3067 = v3060->regs;
  v3067[20] = v3066;
  struct StateT * v3069 = slot_268(v3060);
  return v3069;
}

struct StateT * slot_201(struct StateT * v5068) {
  int v5069 = v5068->timer;
  int v5077 = v5069 + 1;
  v5068->timer = v5077;
  int * v5071 = v5068->regs;
  int v5072 = v5071[6];
  int * v5073 = v5068->regs;
  int v5082 = (int)((unsigned int)v5072 >> 14);
  v5073[9] = v5082;
  struct StateT * v5075 = slot_202(v5068);
  return v5075;
}

struct StateT * slot_94(struct StateT * v2653) {
  int v2654 = v2653->timer;
  int v2664 = v2654 + 1;
  v2653->timer = v2664;
  int * v2656 = v2653->regs;
  int v2657 = v2656[25];
  int * v2658 = v2653->regs;
  int v2659 = v2658[14];
  int * v2660 = v2653->regs;
  int v2671 = v2657 + v2659;
  v2660[18] = v2671;
  struct StateT * v2662 = slot_95(v2653);
  return v2662;
}

struct StateT * slot_63(struct StateT * v1455) {
  int v1456 = v1455->timer;
  int v1466 = v1456 + 1;
  v1455->timer = v1466;
  int * v1458 = v1455->regs;
  int v1459 = v1458[18];
  int * v1460 = v1455->regs;
  int v1461 = v1460[20];
  int * v1462 = v1455->regs;
  int v1472 = v1459 | v1461;
  v1462[18] = v1472;
  struct StateT * v1464 = slot_64(v1455);
  return v1464;
}

struct StateT * slot_146(struct StateT * v4022) {
  int v4023 = v4022->timer;
  int v4033 = v4023 + 1;
  v4022->timer = v4033;
  int * v4025 = v4022->regs;
  int v4026 = v4025[17];
  int * v4027 = v4022->regs;
  int v4028 = v4027[5];
  int * v4029 = v4022->regs;
  int v4040 = v4026 | v4028;
  v4029[6] = v4040;
  struct StateT * v4031 = slot_147(v4022);
  return v4031;
}

struct StateT * slot_24(struct StateT * v493) {
  int v494 = v493->timer;
  int v504 = v494 + 1;
  v493->timer = v504;
  int * v496 = v493->regs;
  int v497 = v496[11];
  int * v498 = v493->mem;
  int v508 = (int)((unsigned int)(v497 + 4) >> 2);
  int v499 = v498[v508];
  int * v500 = v493->regs;
  v500[25] = v499;
  struct StateT * v502 = slot_25(v493);
  return v502;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v15 = v6 + -96;
  v7[2] = v15;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_195(struct StateT * v4962) {
  int v4963 = v4962->timer;
  int v4971 = v4963 + 1;
  v4962->timer = v4971;
  int * v4965 = v4962->regs;
  int v4966 = v4965[11];
  int * v4967 = v4962->regs;
  int v4976 = (int)((unsigned int)v4966 >> 14);
  v4967[9] = v4976;
  struct StateT * v4969 = slot_196(v4962);
  return v4969;
}

struct StateT * slot_125(struct StateT * v3629) {
  int v3630 = v3629->timer;
  int v3638 = v3630 + 1;
  v3629->timer = v3638;
  int * v3632 = v3629->regs;
  int v3633 = v3632[5];
  int * v3634 = v3629->regs;
  int v3642 = v3633 << 18;
  v3634[5] = v3642;
  struct StateT * v3636 = slot_126(v3629);
  return v3636;
}

struct StateT * slot_254(struct StateT * v2548) {
  int v2549 = v2548->timer;
  int v2559 = v2549 + 1;
  v2548->timer = v2559;
  int * v2551 = v2548->regs;
  int v2552 = v2551[10];
  int * v2553 = v2548->regs;
  int v2554 = v2553[26];
  int * v2555 = v2548->mem;
  int v2565 = (int)((unsigned int)(v2552 + 32) >> 2);
  v2555[v2565] = v2554;
  struct StateT * v2557 = slot_255(v2548);
  return v2557;
}

struct StateT * slot_148(struct StateT * v4063) {
  int v4064 = v4063->timer;
  int v4074 = v4064 + 1;
  v4063->timer = v4074;
  int * v4066 = v4063->regs;
  int v4067 = v4066[18];
  int * v4068 = v4063->regs;
  int v4069 = v4068[11];
  int * v4070 = v4063->regs;
  int v4081 = v4067 ^ v4069;
  v4070[5] = v4081;
  struct StateT * v4072 = slot_149(v4063);
  return v4072;
}

struct StateT * slot_126(struct StateT * v3645) {
  int v3646 = v3645->timer;
  int v3656 = v3646 + 1;
  v3645->timer = v3656;
  int * v3648 = v3645->regs;
  int v3649 = v3648[5];
  int * v3650 = v3645->regs;
  int v3651 = v3650[6];
  int * v3652 = v3645->regs;
  int v3662 = v3649 | v3651;
  v3652[5] = v3662;
  struct StateT * v3654 = slot_127(v3645);
  return v3654;
}

struct StateT * slot_223(struct StateT * v1361) {
  int v1362 = v1361->timer;
  int v1372 = v1362 + 1;
  v1361->timer = v1372;
  int * v1364 = v1361->regs;
  int v1365 = v1364[25];
  int * v1366 = v1361->regs;
  int v1367 = v1366[7];
  int * v1368 = v1361->regs;
  int v1378 = v1365 + v1367;
  v1368[25] = v1378;
  struct StateT * v1370 = slot_224(v1361);
  return v1370;
}

struct StateT * slot_79(struct StateT * v2057) {
  int v2058 = v2057->timer;
  int v2066 = v2058 + 1;
  v2057->timer = v2066;
  int * v2060 = v2057->regs;
  int v2061 = v2060[8];
  int * v2062 = v2057->regs;
  int v2070 = v2061 << 9;
  v2062[8] = v2070;
  struct StateT * v2064 = slot_80(v2057);
  return v2064;
}

struct StateT * slot_237(struct StateT * v1910) {
  int v1911 = v1910->timer;
  int v1917 = v1911 + 1;
  v1910->timer = v1917;
  int * v1913 = v1910->regs;
  v1913[30] = 1797283840;
  struct StateT * v1915 = slot_238(v1910);
  return v1915;
}

struct StateT * slot_41(struct StateT * v793) {
  int v794 = v793->timer;
  int v804 = v794 + 1;
  v793->timer = v804;
  int * v796 = v793->regs;
  int v797 = v796[2];
  int * v798 = v793->regs;
  int v799 = v798[16];
  int * v800 = v793->mem;
  int v810 = (int)((unsigned int)(v797 + 32) >> 2);
  v800[v810] = v799;
  struct StateT * v802 = slot_42(v793);
  return v802;
}

struct StateT * slot_39(struct StateT * v751) {
  int v752 = v751->timer;
  int v762 = v752 + 1;
  v751->timer = v762;
  int * v754 = v751->regs;
  int v755 = v754[2];
  int * v756 = v751->regs;
  int v757 = v756[1];
  int * v758 = v751->mem;
  int v768 = (int)((unsigned int)(v755 + 40) >> 2);
  v758[v768] = v757;
  struct StateT * v760 = slot_40(v751);
  return v760;
}

struct StateT * slot_142(struct StateT * v3953) {
  int v3954 = v3953->timer;
  int v3962 = v3954 + 1;
  v3953->timer = v3962;
  int * v3956 = v3953->regs;
  int v3957 = v3956[16];
  int * v3958 = v3953->regs;
  int v3966 = v3957 << 7;
  v3958[16] = v3966;
  struct StateT * v3960 = slot_143(v3953);
  return v3960;
}

struct StateT * slot_60(struct StateT * v1341) {
  int v1342 = v1341->timer;
  int v1352 = v1342 + 1;
  v1341->timer = v1352;
  int * v1344 = v1341->regs;
  int v1345 = v1344[20];
  int * v1346 = v1341->regs;
  int v1347 = v1346[9];
  int * v1348 = v1341->regs;
  int v1358 = v1345 | v1347;
  v1348[9] = v1358;
  struct StateT * v1350 = slot_61(v1341);
  return v1350;
}

struct StateT * slot_238(struct StateT * v1940) {
  int v1941 = v1940->timer;
  int v1949 = v1941 + 1;
  v1940->timer = v1949;
  int * v1943 = v1940->regs;
  int v1944 = v1943[15];
  int * v1945 = v1940->regs;
  int v1953 = v1944 + -1947;
  v1945[15] = v1953;
  struct StateT * v1947 = slot_239(v1940);
  return v1947;
}

struct StateT * slot_112(struct StateT * v3369) {
  int v3370 = v3369->timer;
  int v3380 = v3370 + 1;
  v3369->timer = v3380;
  int * v3372 = v3369->regs;
  int v3373 = v3372[23];
  int * v3374 = v3369->regs;
  int v3375 = v3374[24];
  int * v3376 = v3369->regs;
  int v3387 = v3373 + v3375;
  v3376[16] = v3387;
  struct StateT * v3378 = slot_113(v3369);
  return v3378;
}

struct StateT * slot_256(struct StateT * v2632) {
  int v2633 = v2632->timer;
  int v2643 = v2633 + 1;
  v2632->timer = v2643;
  int * v2635 = v2632->regs;
  int v2636 = v2635[10];
  int * v2637 = v2632->regs;
  int v2638 = v2637[7];
  int * v2639 = v2632->mem;
  int v2649 = (int)((unsigned int)(v2636 + 40) >> 2);
  v2639[v2649] = v2638;
  struct StateT * v2641 = slot_257(v2632);
  return v2641;
}

struct StateT * slot_272(struct StateT * v3264) {
  int v3265 = v3264->timer;
  int v3275 = v3265 + 1;
  v3264->timer = v3275;
  int * v3267 = v3264->regs;
  int v3268 = v3267[2];
  int * v3269 = v3264->mem;
  int v3279 = (int)((unsigned int)(v3268 + 52) >> 2);
  int v3270 = v3269[v3279];
  int * v3271 = v3264->regs;
  v3271[25] = v3270;
  struct StateT * v3273 = slot_273(v3264);
  return v3273;
}

struct StateT * slot_47(struct StateT * v907) {
  int v908 = v907->timer;
  int v916 = v908 + 1;
  v907->timer = v916;
  int * v910 = v907->regs;
  int v911 = v910[29];
  int * v912 = v907->regs;
  v912[23] = v911;
  struct StateT * v914 = slot_48(v907);
  return v914;
}

struct StateT * slot_214(struct StateT * v1023) {
  int v1024 = v1023->timer;
  int v1034 = v1024 + 1;
  v1023->timer = v1034;
  int * v1026 = v1023->regs;
  int v1027 = v1026[27];
  int * v1028 = v1023->regs;
  int v1029 = v1028[28];
  int * v1030 = v1023->regs;
  int v1040 = v1027 + v1029;
  v1030[28] = v1040;
  struct StateT * v1032 = slot_215(v1023);
  return v1032;
}

struct StateT * slot_29(struct StateT * v582) {
  int v583 = v582->timer;
  int v589 = v583 + 1;
  v582->timer = v589;
  int * v585 = v582->regs;
  v585[14] = 2036477952;
  struct StateT * v587 = slot_30(v582);
  return v587;
}

struct StateT * slot_16(struct StateT * v325) {
  int v326 = v325->timer;
  int v336 = v326 + 1;
  v325->timer = v336;
  int * v328 = v325->regs;
  int v329 = v328[12];
  int * v330 = v325->mem;
  int v340 = (int)((unsigned int)(v329 + 4) >> 2);
  int v331 = v330[v340];
  int * v332 = v325->regs;
  v332[28] = v331;
  struct StateT * v334 = slot_17(v325);
  return v334;
}

struct StateT * slot_245(struct StateT * v2186) {
  int v2187 = v2186->timer;
  int v2197 = v2187 + 1;
  v2186->timer = v2197;
  int * v2189 = v2186->regs;
  int v2190 = v2189[22];
  int * v2191 = v2186->regs;
  int v2192 = v2191[30];
  int * v2193 = v2186->regs;
  int v2203 = v2190 + v2192;
  v2193[30] = v2203;
  struct StateT * v2195 = slot_246(v2186);
  return v2195;
}

struct StateT * slot_113(struct StateT * v3406) {
  int v3407 = v3406->timer;
  int v3417 = v3407 + 1;
  v3406->timer = v3417;
  int * v3409 = v3406->regs;
  int v3410 = v3409[18];
  int * v3411 = v3406->regs;
  int v3412 = v3411[27];
  int * v3413 = v3406->regs;
  int v3424 = v3410 + v3412;
  v3413[17] = v3424;
  struct StateT * v3415 = slot_114(v3406);
  return v3415;
}

struct StateT * slot_151(struct StateT * v4126) {
  int v4127 = v4126->timer;
  int v4137 = v4127 + 1;
  v4126->timer = v4137;
  int * v4129 = v4126->regs;
  int v4130 = v4129[23];
  int * v4131 = v4126->regs;
  int v4132 = v4131[21];
  int * v4133 = v4126->regs;
  int v4144 = v4130 + v4132;
  v4133[11] = v4144;
  struct StateT * v4135 = slot_152(v4126);
  return v4135;
}

struct StateT * slot_7(struct StateT * v144) {
  int v145 = v144->timer;
  int v155 = v145 + 1;
  v144->timer = v155;
  int * v147 = v144->regs;
  int v148 = v147[2];
  int * v149 = v144->regs;
  int v150 = v149[21];
  int * v151 = v144->mem;
  int v161 = (int)((unsigned int)(v148 + 68) >> 2);
  v151[v161] = v150;
  struct StateT * v153 = slot_8(v144);
  return v153;
}

struct StateT * slot_124(struct StateT * v3612) {
  int v3613 = v3612->timer;
  int v3621 = v3613 + 1;
  v3612->timer = v3621;
  int * v3615 = v3612->regs;
  int v3616 = v3615[5];
  int * v3617 = v3612->regs;
  int v3626 = (int)((unsigned int)v3616 >> 14);
  v3617[6] = v3626;
  struct StateT * v3619 = slot_125(v3612);
  return v3619;
}

struct StateT * slot_191(struct StateT * v4878) {
  int v4879 = v4878->timer;
  int v4889 = v4879 + 1;
  v4878->timer = v4889;
  int * v4881 = v4878->regs;
  int v4882 = v4881[14];
  int * v4883 = v4878->regs;
  int v4884 = v4883[27];
  int * v4885 = v4878->regs;
  int v4896 = v4882 + v4884;
  v4885[11] = v4896;
  struct StateT * v4887 = slot_192(v4878);
  return v4887;
}

struct StateT * slot_103(struct StateT * v3002) {
  int v3003 = v3002->timer;
  int v3013 = v3003 + 1;
  v3002->timer = v3013;
  int * v3005 = v3002->regs;
  int v3006 = v3005[9];
  int * v3007 = v3002->regs;
  int v3008 = v3007[20];
  int * v3009 = v3002->regs;
  int v3019 = v3006 | v3008;
  v3009[20] = v3019;
  struct StateT * v3011 = slot_104(v3002);
  return v3011;
}

struct StateT * slot_128(struct StateT * v3685) {
  int v3686 = v3685->timer;
  int v3696 = v3686 + 1;
  v3685->timer = v3696;
  int * v3688 = v3685->regs;
  int v3689 = v3688[11];
  int * v3690 = v3685->regs;
  int v3691 = v3690[16];
  int * v3692 = v3685->regs;
  int v3703 = v3689 ^ v3691;
  v3692[20] = v3703;
  struct StateT * v3694 = slot_129(v3685);
  return v3694;
}

struct StateT * slot_19(struct StateT * v388) {
  int v389 = v388->timer;
  int v399 = v389 + 1;
  v388->timer = v399;
  int * v391 = v388->regs;
  int v392 = v391[12];
  int * v393 = v388->mem;
  int v403 = (int)((unsigned int)(v392 + 16) >> 2);
  int v394 = v393[v403];
  int * v395 = v388->regs;
  v395[17] = v394;
  struct StateT * v397 = slot_20(v388);
  return v397;
}

struct StateT * slot_87(struct StateT * v2363) {
  int v2364 = v2363->timer;
  int v2374 = v2364 + 1;
  v2363->timer = v2374;
  int * v2366 = v2363->regs;
  int v2367 = v2366[26];
  int * v2368 = v2363->regs;
  int v2369 = v2368[15];
  int * v2370 = v2363->regs;
  int v2380 = v2367 ^ v2369;
  v2370[26] = v2380;
  struct StateT * v2372 = slot_88(v2363);
  return v2372;
}

struct StateT * slot_67(struct StateT * v1603) {
  int v1604 = v1603->timer;
  int v1614 = v1604 + 1;
  v1603->timer = v1614;
  int * v1606 = v1603->regs;
  int v1607 = v1606[12];
  int * v1608 = v1603->regs;
  int v1609 = v1608[15];
  int * v1610 = v1603->regs;
  int v1620 = v1607 ^ v1609;
  v1610[12] = v1620;
  struct StateT * v1612 = slot_68(v1603);
  return v1612;
}

struct StateT * slot_81(struct StateT * v2133) {
  int v2134 = v2133->timer;
  int v2142 = v2134 + 1;
  v2133->timer = v2142;
  int * v2136 = v2133->regs;
  int v2137 = v2136[9];
  int * v2138 = v2133->regs;
  int v2147 = (int)((unsigned int)v2137 >> 23);
  v2138[20] = v2147;
  struct StateT * v2140 = slot_82(v2133);
  return v2140;
}

struct StateT * slot_95(struct StateT * v2695) {
  int v2696 = v2695->timer;
  int v2704 = v2696 + 1;
  v2695->timer = v2704;
  int * v2698 = v2695->regs;
  int v2699 = v2698[15];
  int * v2700 = v2695->regs;
  int v2709 = (int)((unsigned int)v2699 >> 19);
  v2700[20] = v2709;
  struct StateT * v2702 = slot_96(v2695);
  return v2702;
}

struct StateT * slot_115(struct StateT * v3453) {
  int v3454 = v3453->timer;
  int v3462 = v3454 + 1;
  v3453->timer = v3462;
  int * v3456 = v3453->regs;
  int v3457 = v3456[15];
  int * v3458 = v3453->regs;
  int v3467 = (int)((unsigned int)v3457 >> 14);
  v3458[6] = v3467;
  struct StateT * v3460 = slot_116(v3453);
  return v3460;
}

struct StateT * slot_78(struct StateT * v2024) {
  int v2025 = v2024->timer;
  int v2033 = v2025 + 1;
  v2024->timer = v2033;
  int * v2027 = v2024->regs;
  int v2028 = v2027[8];
  int * v2029 = v2024->regs;
  int v2038 = (int)((unsigned int)v2028 >> 23);
  v2029[20] = v2038;
  struct StateT * v2031 = slot_79(v2024);
  return v2031;
}

struct StateT * slot_32(struct StateT * v629) {
  int v630 = v629->timer;
  int v638 = v630 + 1;
  v629->timer = v638;
  int * v632 = v629->regs;
  int v633 = v632[14];
  int * v634 = v629->regs;
  int v643 = v633 + -718;
  v634[19] = v643;
  struct StateT * v636 = slot_33(v629);
  return v636;
}

struct StateT * slot_205(struct StateT * v5138) {
  int v5139 = v5138->timer;
  int v5147 = v5139 + 1;
  v5138->timer = v5147;
  int * v5141 = v5138->regs;
  int v5142 = v5141[8];
  int * v5143 = v5138->regs;
  int v5151 = v5142 << 18;
  v5143[8] = v5151;
  struct StateT * v5145 = slot_206(v5138);
  return v5145;
}

struct StateT * slot_193(struct StateT * v4920) {
  int v4921 = v4920->timer;
  int v4931 = v4921 + 1;
  v4920->timer = v4931;
  int * v4923 = v4920->regs;
  int v4924 = v4923[13];
  int * v4925 = v4920->regs;
  int v4926 = v4925[26];
  int * v4927 = v4920->regs;
  int v4938 = v4924 + v4926;
  v4927[6] = v4938;
  struct StateT * v4929 = slot_194(v4920);
  return v4929;
}

struct StateT * slot_233(struct StateT * v1744) {
  int v1745 = v1744->timer;
  int v1755 = v1745 + 1;
  v1744->timer = v1755;
  int * v1747 = v1744->regs;
  int v1748 = v1747[2];
  int * v1749 = v1744->mem;
  int v1759 = (int)((unsigned int)(v1748 + 36) >> 2);
  int v1750 = v1749[v1759];
  int * v1751 = v1744->regs;
  v1751[30] = v1750;
  struct StateT * v1753 = slot_234(v1744);
  return v1753;
}

struct StateT * slot_176(struct StateT * v4603) {
  int v4604 = v4603->timer;
  int v4612 = v4604 + 1;
  v4603->timer = v4612;
  int * v4606 = v4603->regs;
  int v4607 = v4606[11];
  int * v4608 = v4603->regs;
  int v4616 = v4607 << 13;
  v4608[11] = v4616;
  struct StateT * v4610 = slot_177(v4603);
  return v4610;
}

struct StateT * slot_189(struct StateT * v4838) {
  int v4839 = v4838->timer;
  int v4849 = v4839 + 1;
  v4838->timer = v4849;
  int * v4841 = v4838->regs;
  int v4842 = v4841[13];
  int * v4843 = v4838->regs;
  int v4844 = v4843[6];
  int * v4845 = v4838->regs;
  int v4855 = v4842 ^ v4844;
  v4845[13] = v4855;
  struct StateT * v4847 = slot_190(v4838);
  return v4847;
}

struct StateT * slot_33(struct StateT * v646) {
  int v647 = v646->timer;
  int v653 = v647 + 1;
  v646->timer = v653;
  int * v649 = v646->regs;
  v649[22] = 1797283840;
  struct StateT * v651 = slot_34(v646);
  return v651;
}

struct StateT * slot_35(struct StateT * v675) {
  int v676 = v675->timer;
  int v682 = v676 + 1;
  v675->timer = v682;
  int * v678 = v675->regs;
  v678[31] = 9;
  struct StateT * v680 = slot_36(v675);
  return v680;
}

struct StateT * slot_258(struct StateT * v2712) {
  int v2713 = v2712->timer;
  int v2723 = v2713 + 1;
  v2712->timer = v2723;
  int * v2715 = v2712->regs;
  int v2716 = v2715[10];
  int * v2717 = v2712->regs;
  int v2718 = v2717[16];
  int * v2719 = v2712->mem;
  int v2729 = (int)((unsigned int)(v2716 + 48) >> 2);
  v2719[v2729] = v2718;
  struct StateT * v2721 = slot_259(v2712);
  return v2721;
}

struct StateT * slot_246(struct StateT * v2226) {
  int v2227 = v2226->timer;
  int v2237 = v2227 + 1;
  v2226->timer = v2237;
  int * v2229 = v2226->regs;
  int v2230 = v2229[10];
  int * v2231 = v2226->regs;
  int v2232 = v2231[15];
  int * v2233 = v2226->mem;
  int v2243 = (int)((unsigned int)v2230 >> 2);
  v2233[v2243] = v2232;
  struct StateT * v2235 = slot_247(v2226);
  return v2235;
}

struct StateT * slot_210(struct StateT * v5235) {
  int v5236 = v5235->timer;
  int v5246 = v5236 + 1;
  v5235->timer = v5246;
  int * v5238 = v5235->regs;
  int v5239 = v5238[22];
  int * v5240 = v5235->regs;
  int v5241 = v5240[8];
  int * v5242 = v5235->regs;
  int v5252 = v5239 ^ v5241;
  v5242[22] = v5252;
  struct StateT * v5244 = slot_211(v5235);
  return v5244;
}

struct StateT * slot_166(struct StateT * v4402) {
  int v4403 = v4402->timer;
  int v4413 = v4403 + 1;
  v4402->timer = v4413;
  int * v4405 = v4402->regs;
  int v4406 = v4405[8];
  int * v4407 = v4402->regs;
  int v4408 = v4407[9];
  int * v4409 = v4402->regs;
  int v4419 = v4406 | v4408;
  v4409[8] = v4419;
  struct StateT * v4411 = slot_167(v4402);
  return v4411;
}

struct StateT * slot_51(struct StateT * v1002) {
  int v1003 = v1002->timer;
  int v1013 = v1003 + 1;
  v1002->timer = v1013;
  int * v1005 = v1002->regs;
  int v1006 = v1005[21];
  int * v1007 = v1002->regs;
  int v1008 = v1007[16];
  int * v1009 = v1002->regs;
  int v1020 = v1006 + v1008;
  v1009[15] = v1020;
  struct StateT * v1011 = slot_52(v1002);
  return v1011;
}

struct StateT * slot_52(struct StateT * v1043) {
  int v1044 = v1043->timer;
  int v1054 = v1044 + 1;
  v1043->timer = v1054;
  int * v1046 = v1043->regs;
  int v1047 = v1046[11];
  int * v1048 = v1043->regs;
  int v1049 = v1048[23];
  int * v1050 = v1043->regs;
  int v1061 = v1047 + v1049;
  v1050[20] = v1061;
  struct StateT * v1052 = slot_53(v1043);
  return v1052;
}

struct StateT * slot_83(struct StateT * v2206) {
  int v2207 = v2206->timer;
  int v2217 = v2207 + 1;
  v2206->timer = v2217;
  int * v2209 = v2206->regs;
  int v2210 = v2209[9];
  int * v2211 = v2206->regs;
  int v2212 = v2211[20];
  int * v2213 = v2206->regs;
  int v2223 = v2210 | v2212;
  v2213[9] = v2223;
  struct StateT * v2215 = slot_84(v2206);
  return v2215;
}

struct StateT * slot_25(struct StateT * v514) {
  int v515 = v514->timer;
  int v525 = v515 + 1;
  v514->timer = v525;
  int * v517 = v514->regs;
  int v518 = v517[11];
  int * v519 = v514->mem;
  int v529 = (int)((unsigned int)(v518 + 8) >> 2);
  int v520 = v519[v529];
  int * v521 = v514->regs;
  v521[26] = v520;
  struct StateT * v523 = slot_26(v514);
  return v523;
}

struct StateT * slot_209(struct StateT * v5215) {
  int v5216 = v5215->timer;
  int v5226 = v5216 + 1;
  v5215->timer = v5226;
  int * v5218 = v5215->regs;
  int v5219 = v5218[19];
  int * v5220 = v5215->regs;
  int v5221 = v5220[6];
  int * v5222 = v5215->regs;
  int v5232 = v5219 ^ v5221;
  v5222[19] = v5232;
  struct StateT * v5224 = slot_210(v5215);
  return v5224;
}

struct StateT * slot_3(struct StateT * v60) {
  int v61 = v60->timer;
  int v71 = v61 + 1;
  v60->timer = v71;
  int * v63 = v60->regs;
  int v64 = v63[2];
  int * v65 = v60->regs;
  int v66 = v65[9];
  int * v67 = v60->mem;
  int v77 = (int)((unsigned int)(v64 + 84) >> 2);
  v67[v77] = v66;
  struct StateT * v69 = slot_4(v60);
  return v69;
}

struct StateT * slot_264(struct StateT * v2944) {
  int v2945 = v2944->timer;
  int v2955 = v2945 + 1;
  v2944->timer = v2955;
  int * v2947 = v2944->regs;
  int v2948 = v2947[2];
  int * v2949 = v2944->mem;
  int v2959 = (int)((unsigned int)(v2948 + 84) >> 2);
  int v2950 = v2949[v2959];
  int * v2951 = v2944->regs;
  v2951[9] = v2950;
  struct StateT * v2953 = slot_265(v2944);
  return v2953;
}

struct StateT * slot_123(struct StateT * v3592) {
  int v3593 = v3592->timer;
  int v3603 = v3593 + 1;
  v3592->timer = v3603;
  int * v3595 = v3592->regs;
  int v3596 = v3595[17];
  int * v3597 = v3592->regs;
  int v3598 = v3597[6];
  int * v3599 = v3592->regs;
  int v3609 = v3596 | v3598;
  v3599[17] = v3609;
  struct StateT * v3601 = slot_124(v3592);
  return v3601;
}

struct StateT * slot_73(struct StateT * v1848) {
  int v1849 = v1848->timer;
  int v1859 = v1849 + 1;
  v1848->timer = v1859;
  int * v1851 = v1848->regs;
  int v1852 = v1851[1];
  int * v1853 = v1848->regs;
  int v1854 = v1853[19];
  int * v1855 = v1848->regs;
  int v1866 = v1852 + v1854;
  v1855[9] = v1866;
  struct StateT * v1857 = slot_74(v1848);
  return v1857;
}

struct StateT * slot_270(struct StateT * v3181) {
  int v3182 = v3181->timer;
  int v3192 = v3182 + 1;
  v3181->timer = v3192;
  int * v3184 = v3181->regs;
  int v3185 = v3184[2];
  int * v3186 = v3181->mem;
  int v3196 = (int)((unsigned int)(v3185 + 60) >> 2);
  int v3187 = v3186[v3196];
  int * v3188 = v3181->regs;
  v3188[23] = v3187;
  struct StateT * v3190 = slot_271(v3181);
  return v3190;
}

struct StateT * slot_198(struct StateT * v5015) {
  int v5016 = v5015->timer;
  int v5024 = v5016 + 1;
  v5015->timer = v5024;
  int * v5018 = v5015->regs;
  int v5019 = v5018[15];
  int * v5020 = v5015->regs;
  int v5029 = (int)((unsigned int)v5019 >> 14);
  v5020[9] = v5029;
  struct StateT * v5022 = slot_199(v5015);
  return v5022;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v29 = v19 + 1;
  v18->timer = v29;
  int * v21 = v18->regs;
  int v22 = v21[2];
  int * v23 = v18->regs;
  int v24 = v23[1];
  int * v25 = v18->mem;
  int v35 = (int)((unsigned int)(v22 + 92) >> 2);
  v25[v35] = v24;
  struct StateT * v27 = slot_2(v18);
  return v27;
}

struct StateT * slot_187(struct StateT * v4798) {
  int v4799 = v4798->timer;
  int v4809 = v4799 + 1;
  v4798->timer = v4809;
  int * v4801 = v4798->regs;
  int v4802 = v4801[14];
  int * v4803 = v4798->regs;
  int v4804 = v4803[11];
  int * v4805 = v4798->regs;
  int v4815 = v4802 ^ v4804;
  v4805[14] = v4815;
  struct StateT * v4807 = slot_188(v4798);
  return v4807;
}

struct StateT * slot_97(struct StateT * v2770) {
  int v2771 = v2770->timer;
  int v2781 = v2771 + 1;
  v2770->timer = v2781;
  int * v2773 = v2770->regs;
  int v2774 = v2773[15];
  int * v2775 = v2770->regs;
  int v2776 = v2775[20];
  int * v2777 = v2770->regs;
  int v2787 = v2774 | v2776;
  v2777[15] = v2787;
  struct StateT * v2779 = slot_98(v2770);
  return v2779;
}

struct StateT * slot_182(struct StateT * v4709) {
  int v4710 = v4709->timer;
  int v4718 = v4710 + 1;
  v4709->timer = v4718;
  int * v4712 = v4709->regs;
  int v4713 = v4712[6];
  int * v4714 = v4709->regs;
  int v4722 = v4713 << 13;
  v4714[6] = v4722;
  struct StateT * v4716 = slot_183(v4709);
  return v4716;
}

struct StateT * slot_38(struct StateT * v730) {
  int v731 = v730->timer;
  int v741 = v731 + 1;
  v730->timer = v741;
  int * v733 = v730->regs;
  int v734 = v733[2];
  int * v735 = v730->regs;
  int v736 = v735[5];
  int * v737 = v730->mem;
  int v747 = (int)((unsigned int)(v734 + 12) >> 2);
  v737[v747] = v736;
  struct StateT * v739 = slot_39(v730);
  return v739;
}

struct StateT * slot_178(struct StateT * v4639) {
  int v4640 = v4639->timer;
  int v4648 = v4640 + 1;
  v4639->timer = v4648;
  int * v4642 = v4639->regs;
  int v4643 = v4642[15];
  int * v4644 = v4639->regs;
  int v4653 = (int)((unsigned int)v4643 >> 19);
  v4644[9] = v4653;
  struct StateT * v4646 = slot_179(v4639);
  return v4646;
}

struct StateT * slot_106(struct StateT * v3118) {
  int v3119 = v3118->timer;
  int v3129 = v3119 + 1;
  v3118->timer = v3129;
  int * v3121 = v3118->regs;
  int v3122 = v3121[18];
  int * v3123 = v3118->regs;
  int v3124 = v3123[9];
  int * v3125 = v3118->regs;
  int v3136 = v3122 | v3124;
  v3125[6] = v3136;
  struct StateT * v3127 = slot_107(v3118);
  return v3127;
}

struct StateT * slot_98(struct StateT * v2811) {
  int v2812 = v2811->timer;
  int v2820 = v2812 + 1;
  v2811->timer = v2820;
  int * v2814 = v2811->regs;
  int v2815 = v2814[8];
  int * v2816 = v2811->regs;
  int v2825 = (int)((unsigned int)v2815 >> 19);
  v2816[20] = v2825;
  struct StateT * v2818 = slot_99(v2811);
  return v2818;
}

struct StateT * slot_159(struct StateT * v4280) {
  int v4281 = v4280->timer;
  int v4289 = v4281 + 1;
  v4280->timer = v4289;
  int * v4283 = v4280->regs;
  int v4284 = v4283[15];
  int * v4285 = v4280->regs;
  int v4293 = v4284 << 9;
  v4285[15] = v4293;
  struct StateT * v4287 = slot_160(v4280);
  return v4287;
}

struct StateT * slot_46(struct StateT * v890) {
  int v891 = v890->timer;
  int v899 = v891 + 1;
  v890->timer = v899;
  int * v893 = v890->regs;
  int v894 = v893[28];
  int * v895 = v890->regs;
  v895[27] = v894;
  struct StateT * v897 = slot_47(v890);
  return v897;
}

struct StateT * slot_212(struct StateT * v5271) {
  int v5272 = v5271->timer;
  int v5284 = v5272 + 1;
  v5271->timer = v5284;
  int * v5274 = v5271->regs;
  int v5275 = v5274[31];
  int * v5276 = v5271->regs;
  int v5277 = v5276[30];
  bool v5289 = (v5275 ^ -2147483648) >= (v5277 ^ -2147483648);
  struct StateT * v5282;
  if (v5289) {
    struct StateT * v5278 = slot_51(v5271);
    v5282 = v5278;
  } else {
    struct StateT * v5280 = slot_213(v5271);
    v5282 = v5280;
  }
  return v5282;
}

struct StateT * slot_132(struct StateT * v3767) {
  int v3768 = v3767->timer;
  int v3778 = v3768 + 1;
  v3767->timer = v3778;
  int * v3770 = v3767->regs;
  int v3771 = v3770[20];
  int * v3772 = v3767->regs;
  int v3773 = v3772[12];
  int * v3774 = v3767->regs;
  int v3785 = v3771 + v3773;
  v3774[11] = v3785;
  struct StateT * v3776 = slot_133(v3767);
  return v3776;
}

struct StateT * slot_130(struct StateT * v3726) {
  int v3727 = v3726->timer;
  int v3737 = v3727 + 1;
  v3726->timer = v3737;
  int * v3729 = v3726->regs;
  int v3730 = v3729[22];
  int * v3731 = v3726->regs;
  int v3732 = v3731[5];
  int * v3733 = v3726->regs;
  int v3743 = v3730 ^ v3732;
  v3733[22] = v3743;
  struct StateT * v3735 = slot_131(v3726);
  return v3735;
}

struct StateT * slot_211(struct StateT * v5255) {
  int v5256 = v5255->timer;
  int v5264 = v5256 + 1;
  v5255->timer = v5264;
  int * v5258 = v5255->regs;
  int v5259 = v5258[30];
  int * v5260 = v5255->regs;
  int v5268 = v5259 + 1;
  v5260[30] = v5268;
  struct StateT * v5262 = slot_212(v5255);
  return v5262;
}

struct StateT * slot_20(struct StateT * v409) {
  int v410 = v409->timer;
  int v420 = v410 + 1;
  v409->timer = v420;
  int * v412 = v409->regs;
  int v413 = v412[12];
  int * v414 = v409->mem;
  int v424 = (int)((unsigned int)(v413 + 20) >> 2);
  int v415 = v414[v424];
  int * v416 = v409->regs;
  v416[16] = v415;
  struct StateT * v418 = slot_21(v409);
  return v418;
}

struct StateT * slot_141(struct StateT * v3936) {
  int v3937 = v3936->timer;
  int v3945 = v3937 + 1;
  v3936->timer = v3945;
  int * v3939 = v3936->regs;
  int v3940 = v3939[16];
  int * v3941 = v3936->regs;
  int v3950 = (int)((unsigned int)v3940 >> 25);
  v3941[5] = v3950;
  struct StateT * v3943 = slot_142(v3936);
  return v3943;
}

struct StateT * slot_61(struct StateT * v1381) {
  int v1382 = v1381->timer;
  int v1390 = v1382 + 1;
  v1381->timer = v1390;
  int * v1384 = v1381->regs;
  int v1385 = v1384[18];
  int * v1386 = v1381->regs;
  int v1395 = (int)((unsigned int)v1385 >> 25);
  v1386[20] = v1395;
  struct StateT * v1388 = slot_62(v1381);
  return v1388;
}

struct StateT * slot_30(struct StateT * v595) {
  int v596 = v595->timer;
  int v604 = v596 + 1;
  v595->timer = v604;
  int * v598 = v595->regs;
  int v599 = v598[12];
  int * v600 = v595->regs;
  int v609 = v599 + -1947;
  v600[21] = v609;
  struct StateT * v602 = slot_31(v595);
  return v602;
}

struct StateT * slot_4(struct StateT * v81) {
  int v82 = v81->timer;
  int v92 = v82 + 1;
  v81->timer = v92;
  int * v84 = v81->regs;
  int v85 = v84[2];
  int * v86 = v81->regs;
  int v87 = v86[18];
  int * v88 = v81->mem;
  int v98 = (int)((unsigned int)(v85 + 80) >> 2);
  v88[v98] = v87;
  struct StateT * v90 = slot_5(v81);
  return v90;
}

struct StateT * slot_18(struct StateT * v367) {
  int v368 = v367->timer;
  int v378 = v368 + 1;
  v367->timer = v378;
  int * v370 = v367->regs;
  int v371 = v370[12];
  int * v372 = v367->mem;
  int v382 = (int)((unsigned int)(v371 + 12) >> 2);
  int v373 = v372[v382];
  int * v374 = v367->regs;
  v374[6] = v373;
  struct StateT * v376 = slot_19(v367);
  return v376;
}

struct StateT * slot_9(struct StateT * v186) {
  int v187 = v186->timer;
  int v197 = v187 + 1;
  v186->timer = v197;
  int * v189 = v186->regs;
  int v190 = v189[2];
  int * v191 = v186->regs;
  int v192 = v191[23];
  int * v193 = v186->mem;
  int v203 = (int)((unsigned int)(v190 + 60) >> 2);
  v193[v203] = v192;
  struct StateT * v195 = slot_10(v186);
  return v195;
}

struct StateT * slot_183(struct StateT * v4725) {
  int v4726 = v4725->timer;
  int v4736 = v4726 + 1;
  v4725->timer = v4736;
  int * v4728 = v4725->regs;
  int v4729 = v4728[6];
  int * v4730 = v4725->regs;
  int v4731 = v4730[9];
  int * v4732 = v4725->regs;
  int v4742 = v4729 | v4731;
  v4732[6] = v4742;
  struct StateT * v4734 = slot_184(v4725);
  return v4734;
}

struct StateT * slot_240(struct StateT * v2008) {
  int v2009 = v2008->timer;
  int v2017 = v2009 + 1;
  v2008->timer = v2017;
  int * v2011 = v2008->regs;
  int v2012 = v2011[7];
  int * v2013 = v2008->regs;
  int v2021 = v2012 + -718;
  v2013[7] = v2021;
  struct StateT * v2015 = slot_241(v2008);
  return v2015;
}

struct StateT * slot_247(struct StateT * v2264) {
  int v2265 = v2264->timer;
  int v2275 = v2265 + 1;
  v2264->timer = v2275;
  int * v2267 = v2264->regs;
  int v2268 = v2267[10];
  int * v2269 = v2264->regs;
  int v2270 = v2269[29];
  int * v2271 = v2264->mem;
  int v2281 = (int)((unsigned int)(v2268 + 4) >> 2);
  v2271[v2281] = v2270;
  struct StateT * v2273 = slot_248(v2264);
  return v2273;
}

struct StateT * slot_43(struct StateT * v835) {
  int v836 = v835->timer;
  int v846 = v836 + 1;
  v835->timer = v846;
  int * v838 = v835->regs;
  int v839 = v838[2];
  int * v840 = v835->regs;
  int v841 = v840[6];
  int * v842 = v835->mem;
  int v852 = (int)((unsigned int)(v839 + 8) >> 2);
  v842[v852] = v841;
  struct StateT * v844 = slot_44(v835);
  return v844;
}

struct StateT * slot_70(struct StateT * v1724) {
  int v1725 = v1724->timer;
  int v1735 = v1725 + 1;
  v1724->timer = v1735;
  int * v1727 = v1724->regs;
  int v1728 = v1727[14];
  int * v1729 = v1724->regs;
  int v1730 = v1729[8];
  int * v1731 = v1724->regs;
  int v1741 = v1728 ^ v1730;
  v1731[14] = v1741;
  struct StateT * v1733 = slot_71(v1724);
  return v1733;
}

struct StateT * slot_168(struct StateT * v4442) {
  int v4443 = v4442->timer;
  int v4453 = v4443 + 1;
  v4442->timer = v4453;
  int * v4445 = v4442->regs;
  int v4446 = v4445[25];
  int * v4447 = v4442->regs;
  int v4448 = v4447[15];
  int * v4449 = v4442->regs;
  int v4459 = v4446 ^ v4448;
  v4449[25] = v4459;
  struct StateT * v4451 = slot_169(v4442);
  return v4451;
}

struct StateT * slot_76(struct StateT * v1956) {
  int v1957 = v1956->timer;
  int v1965 = v1957 + 1;
  v1956->timer = v1965;
  int * v1959 = v1956->regs;
  int v1960 = v1959[15];
  int * v1961 = v1956->regs;
  int v1969 = v1960 << 9;
  v1961[15] = v1969;
  struct StateT * v1963 = slot_77(v1956);
  return v1963;
}

struct StateT * slot_6(struct StateT * v123) {
  int v124 = v123->timer;
  int v134 = v124 + 1;
  v123->timer = v134;
  int * v126 = v123->regs;
  int v127 = v126[2];
  int * v128 = v123->regs;
  int v129 = v128[20];
  int * v130 = v123->mem;
  int v140 = (int)((unsigned int)(v127 + 72) >> 2);
  v130[v140] = v129;
  struct StateT * v132 = slot_7(v123);
  return v132;
}

struct StateT * slot_225(struct StateT * v1435) {
  int v1436 = v1435->timer;
  int v1446 = v1436 + 1;
  v1435->timer = v1446;
  int * v1438 = v1435->regs;
  int v1439 = v1438[26];
  int * v1440 = v1435->regs;
  int v1441 = v1440[7];
  int * v1442 = v1435->regs;
  int v1452 = v1439 + v1441;
  v1442[26] = v1452;
  struct StateT * v1444 = slot_226(v1435);
  return v1444;
}

struct StateT * slot_55(struct StateT * v1160) {
  int v1161 = v1160->timer;
  int v1169 = v1161 + 1;
  v1160->timer = v1169;
  int * v1163 = v1160->regs;
  int v1164 = v1163[15];
  int * v1165 = v1160->regs;
  int v1174 = (int)((unsigned int)v1164 >> 25);
  v1165[9] = v1174;
  struct StateT * v1167 = slot_56(v1160);
  return v1167;
}

struct StateT * slot_213(struct StateT * v982) {
  int v983 = v982->timer;
  int v993 = v983 + 1;
  v982->timer = v993;
  int * v985 = v982->regs;
  int v986 = v985[23];
  int * v987 = v982->regs;
  int v988 = v987[29];
  int * v989 = v982->regs;
  int v999 = v986 + v988;
  v989[29] = v999;
  struct StateT * v991 = slot_214(v982);
  return v991;
}

struct StateT * slot_82(struct StateT * v2170) {
  int v2171 = v2170->timer;
  int v2179 = v2171 + 1;
  v2170->timer = v2179;
  int * v2173 = v2170->regs;
  int v2174 = v2173[9];
  int * v2175 = v2170->regs;
  int v2183 = v2174 << 9;
  v2175[9] = v2183;
  struct StateT * v2177 = slot_83(v2170);
  return v2177;
}

struct StateT * slot_274(struct StateT * v3348) {
  int v3349 = v3348->timer;
  int v3359 = v3349 + 1;
  v3348->timer = v3359;
  int * v3351 = v3348->regs;
  int v3352 = v3351[2];
  int * v3353 = v3348->mem;
  int v3363 = (int)((unsigned int)(v3352 + 44) >> 2);
  int v3354 = v3353[v3363];
  int * v3355 = v3348->regs;
  v3355[27] = v3354;
  struct StateT * v3357 = slot_275(v3348);
  return v3357;
}

struct StateT * slot_263(struct StateT * v2906) {
  int v2907 = v2906->timer;
  int v2917 = v2907 + 1;
  v2906->timer = v2917;
  int * v2909 = v2906->regs;
  int v2910 = v2909[2];
  int * v2911 = v2906->mem;
  int v2921 = (int)((unsigned int)(v2910 + 88) >> 2);
  int v2912 = v2911[v2921];
  int * v2913 = v2906->regs;
  v2913[8] = v2912;
  struct StateT * v2915 = slot_264(v2906);
  return v2915;
}

struct StateT * slot_161(struct StateT * v4316) {
  int v4317 = v4316->timer;
  int v4325 = v4317 + 1;
  v4316->timer = v4325;
  int * v4319 = v4316->regs;
  int v4320 = v4319[6];
  int * v4321 = v4316->regs;
  int v4330 = (int)((unsigned int)v4320 >> 23);
  v4321[9] = v4330;
  struct StateT * v4323 = slot_162(v4316);
  return v4323;
}

struct StateT * slot_185(struct StateT * v4762) {
  int v4763 = v4762->timer;
  int v4771 = v4763 + 1;
  v4762->timer = v4771;
  int * v4765 = v4762->regs;
  int v4766 = v4765[8];
  int * v4767 = v4762->regs;
  int v4775 = v4766 << 13;
  v4767[8] = v4775;
  struct StateT * v4769 = slot_186(v4762);
  return v4769;
}

struct StateT * slot_91(struct StateT * v2527) {
  int v2528 = v2527->timer;
  int v2538 = v2528 + 1;
  v2527->timer = v2538;
  int * v2530 = v2527->regs;
  int v2531 = v2530[26];
  int * v2532 = v2527->regs;
  int v2533 = v2532[12];
  int * v2534 = v2527->regs;
  int v2545 = v2531 + v2533;
  v2534[15] = v2545;
  struct StateT * v2536 = slot_92(v2527);
  return v2536;
}

struct StateT * slot_58(struct StateT * v1267) {
  int v1268 = v1267->timer;
  int v1276 = v1268 + 1;
  v1267->timer = v1276;
  int * v1270 = v1267->regs;
  int v1271 = v1270[20];
  int * v1272 = v1267->regs;
  int v1281 = (int)((unsigned int)v1271 >> 25);
  v1272[9] = v1281;
  struct StateT * v1274 = slot_59(v1267);
  return v1274;
}

struct StateT * slot_89(struct StateT * v2445) {
  int v2446 = v2445->timer;
  int v2456 = v2446 + 1;
  v2445->timer = v2456;
  int * v2448 = v2445->regs;
  int v2449 = v2448[27];
  int * v2450 = v2445->regs;
  int v2451 = v2450[9];
  int * v2452 = v2445->regs;
  int v2462 = v2449 ^ v2451;
  v2452[27] = v2462;
  struct StateT * v2454 = slot_90(v2445);
  return v2454;
}

struct StateT * slot_255(struct StateT * v2590) {
  int v2591 = v2590->timer;
  int v2601 = v2591 + 1;
  v2590->timer = v2601;
  int * v2593 = v2590->regs;
  int v2594 = v2593[10];
  int * v2595 = v2590->regs;
  int v2596 = v2595[13];
  int * v2597 = v2590->mem;
  int v2607 = (int)((unsigned int)(v2594 + 36) >> 2);
  v2597[v2607] = v2596;
  struct StateT * v2599 = slot_256(v2590);
  return v2599;
}

struct StateT * slot_66(struct StateT * v1562) {
  int v1563 = v1562->timer;
  int v1573 = v1563 + 1;
  v1562->timer = v1573;
  int * v1565 = v1562->regs;
  int v1566 = v1565[8];
  int * v1567 = v1562->regs;
  int v1568 = v1567[20];
  int * v1569 = v1562->regs;
  int v1579 = v1566 | v1568;
  v1569[8] = v1579;
  struct StateT * v1571 = slot_67(v1562);
  return v1571;
}

struct StateT * slot_140(struct StateT * v3916) {
  int v3917 = v3916->timer;
  int v3927 = v3917 + 1;
  v3916->timer = v3927;
  int * v3919 = v3916->regs;
  int v3920 = v3919[11];
  int * v3921 = v3916->regs;
  int v3922 = v3921[5];
  int * v3923 = v3916->regs;
  int v3933 = v3920 | v3922;
  v3923[11] = v3933;
  struct StateT * v3925 = slot_141(v3916);
  return v3925;
}

struct StateT * slot_265(struct StateT * v2981) {
  int v2982 = v2981->timer;
  int v2992 = v2982 + 1;
  v2981->timer = v2992;
  int * v2984 = v2981->regs;
  int v2985 = v2984[2];
  int * v2986 = v2981->mem;
  int v2996 = (int)((unsigned int)(v2985 + 80) >> 2);
  int v2987 = v2986[v2996];
  int * v2988 = v2981->regs;
  v2988[18] = v2987;
  struct StateT * v2990 = slot_266(v2981);
  return v2990;
}

struct StateT * slot_49(struct StateT * v945) {
  int v946 = v945->timer;
  int v954 = v946 + 1;
  v945->timer = v954;
  int * v948 = v945->regs;
  int v949 = v948[15];
  int * v950 = v945->regs;
  v950[13] = v949;
  struct StateT * v952 = slot_50(v945);
  return v952;
}

struct StateT * slot_216(struct StateT * v1098) {
  int v1099 = v1098->timer;
  int v1109 = v1099 + 1;
  v1098->timer = v1109;
  int * v1101 = v1098->regs;
  int v1102 = v1101[14];
  int * v1103 = v1098->regs;
  int v1104 = v1103[7];
  int * v1105 = v1098->regs;
  int v1115 = v1102 + v1104;
  v1105[14] = v1115;
  struct StateT * v1107 = slot_217(v1098);
  return v1107;
}

struct StateT * slot_50(struct StateT * v962) {
  int v963 = v962->timer;
  int v973 = v963 + 1;
  v962->timer = v973;
  int * v965 = v962->regs;
  int v966 = v965[31];
  bool v976 = (v966 ^ -2147483648) < -2147483648;
  struct StateT * v971;
  if (v976) {
    struct StateT * v967 = slot_213(v962);
    v971 = v967;
  } else {
    struct StateT * v969 = slot_51(v962);
    v971 = v969;
  }
  return v971;
}

struct StateT * slot_37(struct StateT * v709) {
  int v710 = v709->timer;
  int v720 = v710 + 1;
  v709->timer = v720;
  int * v712 = v709->regs;
  int v713 = v712[2];
  int * v714 = v709->regs;
  int v715 = v714[25];
  int * v716 = v709->mem;
  int v726 = (int)((unsigned int)(v713 + 16) >> 2);
  v716[v726] = v715;
  struct StateT * v718 = slot_38(v709);
  return v718;
}

struct StateT * slot_114(struct StateT * v3432) {
  int v3433 = v3432->timer;
  int v3443 = v3433 + 1;
  v3432->timer = v3443;
  int * v3435 = v3432->regs;
  int v3436 = v3435[8];
  int * v3437 = v3432->regs;
  int v3438 = v3437[25];
  int * v3439 = v3432->regs;
  int v3450 = v3436 + v3438;
  v3439[5] = v3450;
  struct StateT * v3441 = slot_115(v3432);
  return v3441;
}

struct StateT * slot_135(struct StateT * v3830) {
  int v3831 = v3830->timer;
  int v3839 = v3831 + 1;
  v3830->timer = v3839;
  int * v3833 = v3830->regs;
  int v3834 = v3833[15];
  int * v3835 = v3830->regs;
  int v3844 = (int)((unsigned int)v3834 >> 25);
  v3835[5] = v3844;
  struct StateT * v3837 = slot_136(v3830);
  return v3837;
}

struct StateT * slot_248(struct StateT * v2301) {
  int v2302 = v2301->timer;
  int v2312 = v2302 + 1;
  v2301->timer = v2312;
  int * v2304 = v2301->regs;
  int v2305 = v2304[10];
  int * v2306 = v2301->regs;
  int v2307 = v2306[28];
  int * v2308 = v2301->mem;
  int v2318 = (int)((unsigned int)(v2305 + 8) >> 2);
  v2308[v2318] = v2307;
  struct StateT * v2310 = slot_249(v2301);
  return v2310;
}

struct StateT * slot_257(struct StateT * v2674) {
  int v2675 = v2674->timer;
  int v2685 = v2675 + 1;
  v2674->timer = v2685;
  int * v2677 = v2674->regs;
  int v2678 = v2677[10];
  int * v2679 = v2674->regs;
  int v2680 = v2679[17];
  int * v2681 = v2674->mem;
  int v2691 = (int)((unsigned int)(v2678 + 44) >> 2);
  v2681[v2691] = v2680;
  struct StateT * v2683 = slot_258(v2674);
  return v2683;
}

struct StateT * slot_59(struct StateT * v1304) {
  int v1305 = v1304->timer;
  int v1313 = v1305 + 1;
  v1304->timer = v1313;
  int * v1307 = v1304->regs;
  int v1308 = v1307[20];
  int * v1309 = v1304->regs;
  int v1317 = v1308 << 7;
  v1309[20] = v1317;
  struct StateT * v1311 = slot_60(v1304);
  return v1311;
}

struct StateT * slot_192(struct StateT * v4899) {
  int v4900 = v4899->timer;
  int v4910 = v4900 + 1;
  v4899->timer = v4910;
  int * v4902 = v4899->regs;
  int v4903 = v4902[12];
  int * v4904 = v4899->regs;
  int v4905 = v4904[25];
  int * v4906 = v4899->regs;
  int v4917 = v4903 + v4905;
  v4906[15] = v4917;
  struct StateT * v4908 = slot_193(v4899);
  return v4908;
}

struct StateT * slot_40(struct StateT * v772) {
  int v773 = v772->timer;
  int v783 = v773 + 1;
  v772->timer = v783;
  int * v775 = v772->regs;
  int v776 = v775[2];
  int * v777 = v772->regs;
  int v778 = v777[24];
  int * v779 = v772->mem;
  int v789 = (int)((unsigned int)(v776 + 36) >> 2);
  v779[v789] = v778;
  struct StateT * v781 = slot_41(v772);
  return v781;
}

struct StateT * slot_48(struct StateT * v924) {
  int v925 = v924->timer;
  int v935 = v925 + 1;
  v924->timer = v935;
  int * v927 = v924->regs;
  int v928 = v927[2];
  int * v929 = v924->regs;
  int v930 = v929[15];
  int * v931 = v924->mem;
  int v941 = (int)((unsigned int)(v928 + 24) >> 2);
  v931[v941] = v930;
  struct StateT * v933 = slot_49(v924);
  return v933;
}

struct StateT * slot_77(struct StateT * v1988) {
  int v1989 = v1988->timer;
  int v1999 = v1989 + 1;
  v1988->timer = v1999;
  int * v1991 = v1988->regs;
  int v1992 = v1991[15];
  int * v1993 = v1988->regs;
  int v1994 = v1993[20];
  int * v1995 = v1988->regs;
  int v2005 = v1992 | v1994;
  v1995[15] = v2005;
  struct StateT * v1997 = slot_78(v1988);
  return v1997;
}

struct StateT * slot_85(struct StateT * v2285) {
  int v2286 = v2285->timer;
  int v2294 = v2286 + 1;
  v2285->timer = v2294;
  int * v2288 = v2285->regs;
  int v2289 = v2288[18];
  int * v2290 = v2285->regs;
  int v2298 = v2289 << 9;
  v2290[18] = v2298;
  struct StateT * v2292 = slot_86(v2285);
  return v2292;
}

struct StateT * slot_75(struct StateT * v1923) {
  int v1924 = v1923->timer;
  int v1932 = v1924 + 1;
  v1923->timer = v1932;
  int * v1926 = v1923->regs;
  int v1927 = v1926[15];
  int * v1928 = v1923->regs;
  int v1937 = (int)((unsigned int)v1927 >> 23);
  v1928[20] = v1937;
  struct StateT * v1930 = slot_76(v1923);
  return v1930;
}

struct StateT * slot_72(struct StateT * v1806) {
  int v1807 = v1806->timer;
  int v1817 = v1807 + 1;
  v1806->timer = v1817;
  int * v1809 = v1806->regs;
  int v1810 = v1809[13];
  int * v1811 = v1806->regs;
  int v1812 = v1811[11];
  int * v1813 = v1806->regs;
  int v1824 = v1810 + v1812;
  v1813[8] = v1824;
  struct StateT * v1815 = slot_73(v1806);
  return v1815;
}

struct StateT * slot_119(struct StateT * v3523) {
  int v3524 = v3523->timer;
  int v3532 = v3524 + 1;
  v3523->timer = v3532;
  int * v3526 = v3523->regs;
  int v3527 = v3526[16];
  int * v3528 = v3523->regs;
  int v3536 = v3527 << 18;
  v3528[16] = v3536;
  struct StateT * v3530 = slot_120(v3523);
  return v3530;
}

struct StateT * slot_71(struct StateT * v1765) {
  int v1766 = v1765->timer;
  int v1776 = v1766 + 1;
  v1765->timer = v1776;
  int * v1768 = v1765->regs;
  int v1769 = v1768[12];
  int * v1770 = v1765->regs;
  int v1771 = v1770[21];
  int * v1772 = v1765->regs;
  int v1783 = v1769 + v1771;
  v1772[15] = v1783;
  struct StateT * v1774 = slot_72(v1765);
  return v1774;
}

struct StateT * slot_101(struct StateT * v2927) {
  int v2928 = v2927->timer;
  int v2936 = v2928 + 1;
  v2927->timer = v2936;
  int * v2930 = v2927->regs;
  int v2931 = v2930[9];
  int * v2932 = v2927->regs;
  int v2941 = (int)((unsigned int)v2931 >> 19);
  v2932[20] = v2941;
  struct StateT * v2934 = slot_102(v2927);
  return v2934;
}

struct StateT * slot_276(struct StateT * v3427) {
  int v3428 = v3427->timer;
  int v3431 = v3428 + 1;
  v3427->timer = v3431;
  return v3427;
}

struct StateT * slot_108(struct StateT * v3202) {
  int v3203 = v3202->timer;
  int v3213 = v3203 + 1;
  v3202->timer = v3213;
  int * v3205 = v3202->regs;
  int v3206 = v3205[23];
  int * v3207 = v3202->regs;
  int v3208 = v3207[8];
  int * v3209 = v3202->regs;
  int v3219 = v3206 ^ v3208;
  v3209[23] = v3219;
  struct StateT * v3211 = slot_109(v3202);
  return v3211;
}

struct StateT * slot_116(struct StateT * v3470) {
  int v3471 = v3470->timer;
  int v3479 = v3471 + 1;
  v3470->timer = v3479;
  int * v3473 = v3470->regs;
  int v3474 = v3473[15];
  int * v3475 = v3470->regs;
  int v3483 = v3474 << 18;
  v3475[15] = v3483;
  struct StateT * v3477 = slot_117(v3470);
  return v3477;
}

struct StateT * slot_93(struct StateT * v2611) {
  int v2612 = v2611->timer;
  int v2622 = v2612 + 1;
  v2611->timer = v2622;
  int * v2614 = v2611->regs;
  int v2615 = v2614[27];
  int * v2616 = v2611->regs;
  int v2617 = v2616[1];
  int * v2618 = v2611->regs;
  int v2629 = v2615 + v2617;
  v2618[9] = v2629;
  struct StateT * v2620 = slot_94(v2611);
  return v2620;
}

struct StateT * slot_266(struct StateT * v3022) {
  int v3023 = v3022->timer;
  int v3033 = v3023 + 1;
  v3022->timer = v3033;
  int * v3025 = v3022->regs;
  int v3026 = v3025[2];
  int * v3027 = v3022->mem;
  int v3037 = (int)((unsigned int)(v3026 + 76) >> 2);
  int v3028 = v3027[v3037];
  int * v3029 = v3022->regs;
  v3029[19] = v3028;
  struct StateT * v3031 = slot_267(v3022);
  return v3031;
}

struct StateT * slot_88(struct StateT * v2404) {
  int v2405 = v2404->timer;
  int v2415 = v2405 + 1;
  v2404->timer = v2415;
  int * v2407 = v2404->regs;
  int v2408 = v2407[24];
  int * v2409 = v2404->regs;
  int v2410 = v2409[8];
  int * v2411 = v2404->regs;
  int v2421 = v2408 ^ v2410;
  v2411[24] = v2421;
  struct StateT * v2413 = slot_89(v2404);
  return v2413;
}

struct StateT * slot_96(struct StateT * v2733) {
  int v2734 = v2733->timer;
  int v2742 = v2734 + 1;
  v2733->timer = v2742;
  int * v2736 = v2733->regs;
  int v2737 = v2736[15];
  int * v2738 = v2733->regs;
  int v2746 = v2737 << 13;
  v2738[15] = v2746;
  struct StateT * v2740 = slot_97(v2733);
  return v2740;
}

struct StateT * slot_215(struct StateT * v1064) {
  int v1065 = v1064->timer;
  int v1071 = v1065 + 1;
  v1064->timer = v1071;
  int * v1067 = v1064->regs;
  v1067[15] = 1634762752;
  struct StateT * v1069 = slot_216(v1064);
  return v1069;
}

struct StateT * slot_234(struct StateT * v1786) {
  int v1787 = v1786->timer;
  int v1797 = v1787 + 1;
  v1786->timer = v1797;
  int * v1789 = v1786->regs;
  int v1790 = v1789[24];
  int * v1791 = v1786->regs;
  int v1792 = v1791[30];
  int * v1793 = v1786->regs;
  int v1803 = v1790 + v1792;
  v1793[24] = v1803;
  struct StateT * v1795 = slot_235(v1786);
  return v1795;
}

struct StateT * slot_45(struct StateT * v873) {
  int v874 = v873->timer;
  int v882 = v874 + 1;
  v873->timer = v882;
  int * v876 = v873->regs;
  int v877 = v876[7];
  int * v878 = v873->regs;
  v878[14] = v877;
  struct StateT * v880 = slot_46(v873);
  return v880;
}

struct StateT * slot_218(struct StateT * v1177) {
  int v1178 = v1177->timer;
  int v1188 = v1178 + 1;
  v1177->timer = v1188;
  int * v1180 = v1177->regs;
  int v1181 = v1180[12];
  int * v1182 = v1177->regs;
  int v1183 = v1182[6];
  int * v1184 = v1177->regs;
  int v1194 = v1181 + v1183;
  v1184[12] = v1194;
  struct StateT * v1186 = slot_219(v1177);
  return v1186;
}

struct StateT * slot_220(struct StateT * v1246) {
  int v1247 = v1246->timer;
  int v1257 = v1247 + 1;
  v1246->timer = v1257;
  int * v1249 = v1246->regs;
  int v1250 = v1249[2];
  int * v1251 = v1246->mem;
  int v1261 = (int)((unsigned int)(v1250 + 12) >> 2);
  int v1252 = v1251[v1261];
  int * v1253 = v1246->regs;
  v1253[7] = v1252;
  struct StateT * v1255 = slot_221(v1246);
  return v1255;
}

struct StateT * slot_134(struct StateT * v3809) {
  int v3810 = v3809->timer;
  int v3820 = v3810 + 1;
  v3809->timer = v3820;
  int * v3812 = v3809->regs;
  int v3813 = v3812[22];
  int * v3814 = v3809->regs;
  int v3815 = v3814[1];
  int * v3816 = v3809->regs;
  int v3827 = v3813 + v3815;
  v3816[17] = v3827;
  struct StateT * v3818 = slot_135(v3809);
  return v3818;
}

struct StateT * slot_175(struct StateT * v4586) {
  int v4587 = v4586->timer;
  int v4595 = v4587 + 1;
  v4586->timer = v4595;
  int * v4589 = v4586->regs;
  int v4590 = v4589[11];
  int * v4591 = v4586->regs;
  int v4600 = (int)((unsigned int)v4590 >> 19);
  v4591[9] = v4600;
  struct StateT * v4593 = slot_176(v4586);
  return v4593;
}

struct StateT * slot_273(struct StateT * v3306) {
  int v3307 = v3306->timer;
  int v3317 = v3307 + 1;
  v3306->timer = v3317;
  int * v3309 = v3306->regs;
  int v3310 = v3309[2];
  int * v3311 = v3306->mem;
  int v3321 = (int)((unsigned int)(v3310 + 48) >> 2);
  int v3312 = v3311[v3321];
  int * v3313 = v3306->regs;
  v3313[26] = v3312;
  struct StateT * v3315 = slot_274(v3306);
  return v3315;
}

struct StateT * slot_69(struct StateT * v1684) {
  int v1685 = v1684->timer;
  int v1695 = v1685 + 1;
  v1684->timer = v1695;
  int * v1687 = v1684->regs;
  int v1688 = v1687[1];
  int * v1689 = v1684->regs;
  int v1690 = v1689[18];
  int * v1691 = v1684->regs;
  int v1701 = v1688 ^ v1690;
  v1691[1] = v1701;
  struct StateT * v1693 = slot_70(v1684);
  return v1693;
}

struct StateT * slot_202(struct StateT * v5085) {
  int v5086 = v5085->timer;
  int v5094 = v5086 + 1;
  v5085->timer = v5094;
  int * v5088 = v5085->regs;
  int v5089 = v5088[6];
  int * v5090 = v5085->regs;
  int v5098 = v5089 << 18;
  v5090[6] = v5098;
  struct StateT * v5092 = slot_203(v5085);
  return v5092;
}

struct StateT * slot_230(struct StateT * v1623) {
  int v1624 = v1623->timer;
  int v1634 = v1624 + 1;
  v1623->timer = v1634;
  int * v1626 = v1623->regs;
  int v1627 = v1626[17];
  int * v1628 = v1623->regs;
  int v1629 = v1628[30];
  int * v1630 = v1623->regs;
  int v1640 = v1627 + v1629;
  v1630[17] = v1640;
  struct StateT * v1632 = slot_231(v1623);
  return v1632;
}

struct StateT * slot_188(struct StateT * v4818) {
  int v4819 = v4818->timer;
  int v4829 = v4819 + 1;
  v4818->timer = v4829;
  int * v4821 = v4818->regs;
  int v4822 = v4821[12];
  int * v4823 = v4818->regs;
  int v4824 = v4823[15];
  int * v4825 = v4818->regs;
  int v4835 = v4822 ^ v4824;
  v4825[12] = v4835;
  struct StateT * v4827 = slot_189(v4818);
  return v4827;
}

struct StateT * slot_138(struct StateT * v3883) {
  int v3884 = v3883->timer;
  int v3892 = v3884 + 1;
  v3883->timer = v3892;
  int * v3886 = v3883->regs;
  int v3887 = v3886[11];
  int * v3888 = v3883->regs;
  int v3897 = (int)((unsigned int)v3887 >> 25);
  v3888[5] = v3897;
  struct StateT * v3890 = slot_139(v3883);
  return v3890;
}

struct StateT * slot_186(struct StateT * v4778) {
  int v4779 = v4778->timer;
  int v4789 = v4779 + 1;
  v4778->timer = v4789;
  int * v4781 = v4778->regs;
  int v4782 = v4781[8];
  int * v4783 = v4778->regs;
  int v4784 = v4783[9];
  int * v4785 = v4778->regs;
  int v4795 = v4782 | v4784;
  v4785[8] = v4795;
  struct StateT * v4787 = slot_187(v4778);
  return v4787;
}

struct StateT * slot_102(struct StateT * v2965) {
  int v2966 = v2965->timer;
  int v2974 = v2966 + 1;
  v2965->timer = v2974;
  int * v2968 = v2965->regs;
  int v2969 = v2968[9];
  int * v2970 = v2965->regs;
  int v2978 = v2969 << 13;
  v2970[9] = v2978;
  struct StateT * v2972 = slot_103(v2965);
  return v2972;
}

struct StateT * slot_145(struct StateT * v4006) {
  int v4007 = v4006->timer;
  int v4015 = v4007 + 1;
  v4006->timer = v4015;
  int * v4009 = v4006->regs;
  int v4010 = v4009[17];
  int * v4011 = v4006->regs;
  int v4019 = v4010 << 7;
  v4011[17] = v4019;
  struct StateT * v4013 = slot_146(v4006);
  return v4013;
}

struct StateT * slot_110(struct StateT * v3285) {
  int v3286 = v3285->timer;
  int v3296 = v3286 + 1;
  v3285->timer = v3296;
  int * v3288 = v3285->regs;
  int v3289 = v3288[17];
  int * v3290 = v3285->regs;
  int v3291 = v3290[6];
  int * v3292 = v3285->regs;
  int v3303 = v3289 ^ v3291;
  v3292[8] = v3303;
  struct StateT * v3294 = slot_111(v3285);
  return v3294;
}

struct StateT * slot_196(struct StateT * v4979) {
  int v4980 = v4979->timer;
  int v4988 = v4980 + 1;
  v4979->timer = v4988;
  int * v4982 = v4979->regs;
  int v4983 = v4982[11];
  int * v4984 = v4979->regs;
  int v4992 = v4983 << 18;
  v4984[11] = v4992;
  struct StateT * v4986 = slot_197(v4979);
  return v4986;
}

struct StateT * slot_208(struct StateT * v5194) {
  int v5195 = v5194->timer;
  int v5205 = v5195 + 1;
  v5194->timer = v5205;
  int * v5197 = v5194->regs;
  int v5198 = v5197[20];
  int * v5199 = v5194->regs;
  int v5200 = v5199[15];
  int * v5201 = v5194->regs;
  int v5212 = v5198 ^ v5200;
  v5201[11] = v5212;
  struct StateT * v5203 = slot_209(v5194);
  return v5203;
}

struct StateT * slot_172(struct StateT * v4523) {
  int v4524 = v4523->timer;
  int v4534 = v4524 + 1;
  v4523->timer = v4534;
  int * v4526 = v4523->regs;
  int v4527 = v4526[25];
  int * v4528 = v4523->regs;
  int v4529 = v4528[5];
  int * v4530 = v4523->regs;
  int v4541 = v4527 + v4529;
  v4530[15] = v4541;
  struct StateT * v4532 = slot_173(v4523);
  return v4532;
}

struct StateT * slot_131(struct StateT * v3746) {
  int v3747 = v3746->timer;
  int v3757 = v3747 + 1;
  v3746->timer = v3757;
  int * v3749 = v3746->regs;
  int v3750 = v3749[21];
  int * v3751 = v3746->regs;
  int v3752 = v3751[14];
  int * v3753 = v3746->regs;
  int v3764 = v3750 + v3752;
  v3753[15] = v3764;
  struct StateT * v3755 = slot_132(v3746);
  return v3755;
}

struct StateT * slot_8(struct StateT * v165) {
  int v166 = v165->timer;
  int v176 = v166 + 1;
  v165->timer = v176;
  int * v168 = v165->regs;
  int v169 = v168[2];
  int * v170 = v165->regs;
  int v171 = v170[22];
  int * v172 = v165->mem;
  int v182 = (int)((unsigned int)(v169 + 64) >> 2);
  v172[v182] = v171;
  struct StateT * v174 = slot_9(v165);
  return v174;
}

struct StateT * slot_180(struct StateT * v4672) {
  int v4673 = v4672->timer;
  int v4683 = v4673 + 1;
  v4672->timer = v4683;
  int * v4675 = v4672->regs;
  int v4676 = v4675[15];
  int * v4677 = v4672->regs;
  int v4678 = v4677[9];
  int * v4679 = v4672->regs;
  int v4689 = v4676 | v4678;
  v4679[15] = v4689;
  struct StateT * v4681 = slot_181(v4672);
  return v4681;
}

struct StateT * slot_203(struct StateT * v5101) {
  int v5102 = v5101->timer;
  int v5112 = v5102 + 1;
  v5101->timer = v5112;
  int * v5104 = v5101->regs;
  int v5105 = v5104[6];
  int * v5106 = v5101->regs;
  int v5107 = v5106[9];
  int * v5108 = v5101->regs;
  int v5118 = v5105 | v5107;
  v5108[6] = v5118;
  struct StateT * v5110 = slot_204(v5101);
  return v5110;
}

struct StateT * slot_190(struct StateT * v4858) {
  int v4859 = v4858->timer;
  int v4869 = v4859 + 1;
  v4858->timer = v4869;
  int * v4861 = v4858->regs;
  int v4862 = v4861[1];
  int * v4863 = v4858->regs;
  int v4864 = v4863[8];
  int * v4865 = v4858->regs;
  int v4875 = v4862 ^ v4864;
  v4865[1] = v4875;
  struct StateT * v4867 = slot_191(v4858);
  return v4867;
}

struct StateT * slot_157(struct StateT * v4243) {
  int v4244 = v4243->timer;
  int v4254 = v4244 + 1;
  v4243->timer = v4254;
  int * v4246 = v4243->regs;
  int v4247 = v4246[11];
  int * v4248 = v4243->regs;
  int v4249 = v4248[9];
  int * v4250 = v4243->regs;
  int v4260 = v4247 | v4249;
  v4250[11] = v4260;
  struct StateT * v4252 = slot_158(v4243);
  return v4252;
}

struct StateT * slot_242(struct StateT * v2073) {
  int v2074 = v2073->timer;
  int v2084 = v2074 + 1;
  v2073->timer = v2084;
  int * v2076 = v2073->regs;
  int v2077 = v2076[21];
  int * v2078 = v2073->regs;
  int v2079 = v2078[15];
  int * v2080 = v2073->regs;
  int v2090 = v2077 + v2079;
  v2080[15] = v2090;
  struct StateT * v2082 = slot_243(v2073);
  return v2082;
}

struct StateT * slot_200(struct StateT * v5048) {
  int v5049 = v5048->timer;
  int v5059 = v5049 + 1;
  v5048->timer = v5059;
  int * v5051 = v5048->regs;
  int v5052 = v5051[15];
  int * v5053 = v5048->regs;
  int v5054 = v5053[9];
  int * v5055 = v5048->regs;
  int v5065 = v5052 | v5054;
  v5055[15] = v5065;
  struct StateT * v5057 = slot_201(v5048);
  return v5057;
}

struct StateT * slot_243(struct StateT * v2113) {
  int v2114 = v2113->timer;
  int v2124 = v2114 + 1;
  v2113->timer = v2124;
  int * v2116 = v2113->regs;
  int v2117 = v2116[11];
  int * v2118 = v2113->regs;
  int v2119 = v2118[6];
  int * v2120 = v2113->regs;
  int v2130 = v2117 + v2119;
  v2120[11] = v2130;
  struct StateT * v2122 = slot_244(v2113);
  return v2122;
}

struct StateT * slot_173(struct StateT * v4544) {
  int v4545 = v4544->timer;
  int v4555 = v4545 + 1;
  v4544->timer = v4555;
  int * v4547 = v4544->regs;
  int v4548 = v4547[26];
  int * v4549 = v4544->regs;
  int v4550 = v4549[17];
  int * v4551 = v4544->regs;
  int v4562 = v4548 + v4550;
  v4551[6] = v4562;
  struct StateT * v4553 = slot_174(v4544);
  return v4553;
}

struct StateT * slot_149(struct StateT * v4084) {
  int v4085 = v4084->timer;
  int v4095 = v4085 + 1;
  v4084->timer = v4095;
  int * v4087 = v4084->regs;
  int v4088 = v4087[8];
  int * v4089 = v4084->regs;
  int v4090 = v4089[16];
  int * v4091 = v4084->regs;
  int v4102 = v4088 ^ v4090;
  v4091[17] = v4102;
  struct StateT * v4093 = slot_150(v4084);
  return v4093;
}

struct StateT * slot_5(struct StateT * v102) {
  int v103 = v102->timer;
  int v113 = v103 + 1;
  v102->timer = v113;
  int * v105 = v102->regs;
  int v106 = v105[2];
  int * v107 = v102->regs;
  int v108 = v107[19];
  int * v109 = v102->mem;
  int v119 = (int)((unsigned int)(v106 + 76) >> 2);
  v109[v119] = v108;
  struct StateT * v111 = slot_6(v102);
  return v111;
}

struct StateT * slot_104(struct StateT * v3043) {
  int v3044 = v3043->timer;
  int v3052 = v3044 + 1;
  v3043->timer = v3052;
  int * v3046 = v3043->regs;
  int v3047 = v3046[18];
  int * v3048 = v3043->regs;
  int v3057 = (int)((unsigned int)v3047 >> 19);
  v3048[9] = v3057;
  struct StateT * v3050 = slot_105(v3043);
  return v3050;
}

struct StateT * slot_235(struct StateT * v1827) {
  int v1828 = v1827->timer;
  int v1838 = v1828 + 1;
  v1827->timer = v1838;
  int * v1830 = v1827->regs;
  int v1831 = v1830[2];
  int * v1832 = v1827->mem;
  int v1842 = (int)((unsigned int)(v1831 + 40) >> 2);
  int v1833 = v1832[v1842];
  int * v1834 = v1827->regs;
  v1834[30] = v1833;
  struct StateT * v1836 = slot_236(v1827);
  return v1836;
}

struct StateT * slot_275(struct StateT * v3390) {
  int v3391 = v3390->timer;
  int v3399 = v3391 + 1;
  v3390->timer = v3399;
  int * v3393 = v3390->regs;
  int v3394 = v3393[2];
  int * v3395 = v3390->regs;
  int v3403 = v3394 + 96;
  v3395[2] = v3403;
  struct StateT * v3397 = slot_276(v3390);
  return v3397;
}

struct StateT * slot_54(struct StateT * v1118) {
  int v1119 = v1118->timer;
  int v1129 = v1119 + 1;
  v1118->timer = v1129;
  int * v1121 = v1118->regs;
  int v1122 = v1121[22];
  int * v1123 = v1118->regs;
  int v1124 = v1123[17];
  int * v1125 = v1118->regs;
  int v1136 = v1122 + v1124;
  v1125[8] = v1136;
  struct StateT * v1127 = slot_55(v1118);
  return v1127;
}

struct StateT * slot_26(struct StateT * v535) {
  int v536 = v535->timer;
  int v546 = v536 + 1;
  v535->timer = v546;
  int * v538 = v535->regs;
  int v539 = v538[11];
  int * v540 = v535->mem;
  int v550 = (int)((unsigned int)(v539 + 12) >> 2);
  int v541 = v540[v550];
  int * v542 = v535->regs;
  v542[15] = v541;
  struct StateT * v544 = slot_27(v535);
  return v544;
}

struct StateT * slot_206(struct StateT * v5154) {
  int v5155 = v5154->timer;
  int v5165 = v5155 + 1;
  v5154->timer = v5165;
  int * v5157 = v5154->regs;
  int v5158 = v5157[8];
  int * v5159 = v5154->regs;
  int v5160 = v5159[9];
  int * v5161 = v5154->regs;
  int v5171 = v5158 | v5160;
  v5161[8] = v5171;
  struct StateT * v5163 = slot_207(v5154);
  return v5163;
}

struct StateT * slot_227(struct StateT * v1513) {
  int v1514 = v1513->timer;
  int v1524 = v1514 + 1;
  v1513->timer = v1524;
  int * v1516 = v1513->regs;
  int v1517 = v1516[13];
  int * v1518 = v1513->regs;
  int v1519 = v1518[7];
  int * v1520 = v1513->regs;
  int v1530 = v1517 + v1519;
  v1520[13] = v1530;
  struct StateT * v1522 = slot_228(v1513);
  return v1522;
}

struct StateT * slot_169(struct StateT * v4462) {
  int v4463 = v4462->timer;
  int v4473 = v4463 + 1;
  v4462->timer = v4473;
  int * v4465 = v4462->regs;
  int v4466 = v4465[26];
  int * v4467 = v4462->regs;
  int v4468 = v4467[6];
  int * v4469 = v4462->regs;
  int v4479 = v4466 ^ v4468;
  v4469[26] = v4479;
  struct StateT * v4471 = slot_170(v4462);
  return v4471;
}

struct StateT * slot_253(struct StateT * v2506) {
  int v2507 = v2506->timer;
  int v2517 = v2507 + 1;
  v2506->timer = v2517;
  int * v2509 = v2506->regs;
  int v2510 = v2509[10];
  int * v2511 = v2506->regs;
  int v2512 = v2511[25];
  int * v2513 = v2506->mem;
  int v2523 = (int)((unsigned int)(v2510 + 28) >> 2);
  v2513[v2523] = v2512;
  struct StateT * v2515 = slot_254(v2506);
  return v2515;
}

struct StateT * slot_64(struct StateT * v1496) {
  int v1497 = v1496->timer;
  int v1505 = v1497 + 1;
  v1496->timer = v1505;
  int * v1499 = v1496->regs;
  int v1500 = v1499[8];
  int * v1501 = v1496->regs;
  int v1510 = (int)((unsigned int)v1500 >> 25);
  v1501[20] = v1510;
  struct StateT * v1503 = slot_65(v1496);
  return v1503;
}

struct StateT * slot_170(struct StateT * v4482) {
  int v4483 = v4482->timer;
  int v4493 = v4483 + 1;
  v4482->timer = v4493;
  int * v4485 = v4482->regs;
  int v4486 = v4485[24];
  int * v4487 = v4482->regs;
  int v4488 = v4487[8];
  int * v4489 = v4482->regs;
  int v4499 = v4486 ^ v4488;
  v4489[24] = v4499;
  struct StateT * v4491 = slot_171(v4482);
  return v4491;
}

struct StateT * slot_14(struct StateT * v291) {
  int v292 = v291->timer;
  int v298 = v292 + 1;
  v291->timer = v298;
  int * v294 = v291->regs;
  v294[30] = 0;
  struct StateT * v296 = slot_15(v291);
  return v296;
}

struct StateT * slot_53(struct StateT * v1077) {
  int v1078 = v1077->timer;
  int v1088 = v1078 + 1;
  v1077->timer = v1088;
  int * v1080 = v1077->regs;
  int v1081 = v1080[19];
  int * v1082 = v1077->regs;
  int v1083 = v1082[5];
  int * v1084 = v1077->regs;
  int v1095 = v1081 + v1083;
  v1084[18] = v1095;
  struct StateT * v1086 = slot_54(v1077);
  return v1086;
}

struct StateT * slot_80(struct StateT * v2093) {
  int v2094 = v2093->timer;
  int v2104 = v2094 + 1;
  v2093->timer = v2104;
  int * v2096 = v2093->regs;
  int v2097 = v2096[8];
  int * v2098 = v2093->regs;
  int v2099 = v2098[20];
  int * v2100 = v2093->regs;
  int v2110 = v2097 | v2099;
  v2100[8] = v2110;
  struct StateT * v2102 = slot_81(v2093);
  return v2102;
}

struct StateT * slot_44(struct StateT * v856) {
  int v857 = v856->timer;
  int v865 = v857 + 1;
  v856->timer = v865;
  int * v859 = v856->regs;
  int v860 = v859[6];
  int * v861 = v856->regs;
  v861[12] = v860;
  struct StateT * v863 = slot_45(v856);
  return v863;
}

struct StateT * slot_261(struct StateT * v2828) {
  int v2829 = v2828->timer;
  int v2839 = v2829 + 1;
  v2828->timer = v2839;
  int * v2831 = v2828->regs;
  int v2832 = v2831[10];
  int * v2833 = v2828->regs;
  int v2834 = v2833[30];
  int * v2835 = v2828->mem;
  int v2845 = (int)((unsigned int)(v2832 + 60) >> 2);
  v2835[v2845] = v2834;
  struct StateT * v2837 = slot_262(v2828);
  return v2837;
}

struct StateT * slot_137(struct StateT * v3863) {
  int v3864 = v3863->timer;
  int v3874 = v3864 + 1;
  v3863->timer = v3874;
  int * v3866 = v3863->regs;
  int v3867 = v3866[15];
  int * v3868 = v3863->regs;
  int v3869 = v3868[5];
  int * v3870 = v3863->regs;
  int v3880 = v3867 | v3869;
  v3870[15] = v3880;
  struct StateT * v3872 = slot_138(v3863);
  return v3872;
}

struct StateT * slot_122(struct StateT * v3576) {
  int v3577 = v3576->timer;
  int v3585 = v3577 + 1;
  v3576->timer = v3585;
  int * v3579 = v3576->regs;
  int v3580 = v3579[17];
  int * v3581 = v3576->regs;
  int v3589 = v3580 << 18;
  v3581[17] = v3589;
  struct StateT * v3583 = slot_123(v3576);
  return v3583;
}

struct StateT * slot_99(struct StateT * v2849) {
  int v2850 = v2849->timer;
  int v2858 = v2850 + 1;
  v2849->timer = v2858;
  int * v2852 = v2849->regs;
  int v2853 = v2852[8];
  int * v2854 = v2849->regs;
  int v2862 = v2853 << 13;
  v2854[8] = v2862;
  struct StateT * v2856 = slot_100(v2849);
  return v2856;
}

struct StateT * slot_179(struct StateT * v4656) {
  int v4657 = v4656->timer;
  int v4665 = v4657 + 1;
  v4656->timer = v4665;
  int * v4659 = v4656->regs;
  int v4660 = v4659[15];
  int * v4661 = v4656->regs;
  int v4669 = v4660 << 13;
  v4661[15] = v4669;
  struct StateT * v4663 = slot_180(v4656);
  return v4663;
}

struct StateT * slot_219(struct StateT * v1213) {
  int v1214 = v1213->timer;
  int v1220 = v1214 + 1;
  v1213->timer = v1220;
  int * v1216 = v1213->regs;
  v1216[6] = 857759744;
  struct StateT * v1218 = slot_220(v1213);
  return v1218;
}

struct StateT * slot_36(struct StateT * v688) {
  int v689 = v688->timer;
  int v699 = v689 + 1;
  v688->timer = v699;
  int * v691 = v688->regs;
  int v692 = v691[2];
  int * v693 = v688->regs;
  int v694 = v693[26];
  int * v695 = v688->mem;
  int v705 = (int)((unsigned int)(v692 + 20) >> 2);
  v695[v705] = v694;
  struct StateT * v697 = slot_37(v688);
  return v697;
}

struct StateT * slot_57(struct StateT * v1226) {
  int v1227 = v1226->timer;
  int v1237 = v1227 + 1;
  v1226->timer = v1237;
  int * v1229 = v1226->regs;
  int v1230 = v1229[15];
  int * v1231 = v1226->regs;
  int v1232 = v1231[9];
  int * v1233 = v1226->regs;
  int v1243 = v1230 | v1232;
  v1233[15] = v1243;
  struct StateT * v1235 = slot_58(v1226);
  return v1235;
}

struct StateT * slot_62(struct StateT * v1419) {
  int v1420 = v1419->timer;
  int v1428 = v1420 + 1;
  v1419->timer = v1428;
  int * v1422 = v1419->regs;
  int v1423 = v1422[18];
  int * v1424 = v1419->regs;
  int v1432 = v1423 << 7;
  v1424[18] = v1432;
  struct StateT * v1426 = slot_63(v1419);
  return v1426;
}

struct StateT * slot_22(struct StateT * v451) {
  int v452 = v451->timer;
  int v462 = v452 + 1;
  v451->timer = v462;
  int * v454 = v451->regs;
  int v455 = v454[12];
  int * v456 = v451->mem;
  int v466 = (int)((unsigned int)(v455 + 28) >> 2);
  int v457 = v456[v466];
  int * v458 = v451->regs;
  v458[1] = v457;
  struct StateT * v460 = slot_23(v451);
  return v460;
}

struct StateT * slot_139(struct StateT * v3900) {
  int v3901 = v3900->timer;
  int v3909 = v3901 + 1;
  v3900->timer = v3909;
  int * v3903 = v3900->regs;
  int v3904 = v3903[11];
  int * v3905 = v3900->regs;
  int v3913 = v3904 << 7;
  v3905[11] = v3913;
  struct StateT * v3907 = slot_140(v3900);
  return v3907;
}

struct StateT * slot_221(struct StateT * v1284) {
  int v1285 = v1284->timer;
  int v1295 = v1285 + 1;
  v1284->timer = v1295;
  int * v1287 = v1284->regs;
  int v1288 = v1287[5];
  int * v1289 = v1284->regs;
  int v1290 = v1289[7];
  int * v1291 = v1284->regs;
  int v1301 = v1288 + v1290;
  v1291[5] = v1301;
  struct StateT * v1293 = slot_222(v1284);
  return v1293;
}

struct StateT * slot_23(struct StateT * v472) {
  int v473 = v472->timer;
  int v483 = v473 + 1;
  v472->timer = v483;
  int * v475 = v472->regs;
  int v476 = v475[11];
  int * v477 = v472->mem;
  int v487 = (int)((unsigned int)v476 >> 2);
  int v478 = v477[v487];
  int * v479 = v472->regs;
  v479[5] = v478;
  struct StateT * v481 = slot_24(v472);
  return v481;
}

struct StateT * slot_153(struct StateT * v4168) {
  int v4169 = v4168->timer;
  int v4179 = v4169 + 1;
  v4168->timer = v4179;
  int * v4171 = v4168->regs;
  int v4172 = v4171[17];
  int * v4173 = v4168->regs;
  int v4174 = v4173[19];
  int * v4175 = v4168->regs;
  int v4186 = v4172 + v4174;
  v4175[6] = v4186;
  struct StateT * v4177 = slot_154(v4168);
  return v4177;
}

struct StateT * slot_2(struct StateT * v39) {
  int v40 = v39->timer;
  int v50 = v40 + 1;
  v39->timer = v50;
  int * v42 = v39->regs;
  int v43 = v42[2];
  int * v44 = v39->regs;
  int v45 = v44[8];
  int * v46 = v39->mem;
  int v56 = (int)((unsigned int)(v43 + 88) >> 2);
  v46[v56] = v45;
  struct StateT * v48 = slot_3(v39);
  return v48;
}

struct StateT * slot_86(struct StateT * v2322) {
  int v2323 = v2322->timer;
  int v2333 = v2323 + 1;
  v2322->timer = v2333;
  int * v2325 = v2322->regs;
  int v2326 = v2325[18];
  int * v2327 = v2322->regs;
  int v2328 = v2327[20];
  int * v2329 = v2322->regs;
  int v2339 = v2326 | v2328;
  v2329[18] = v2339;
  struct StateT * v2331 = slot_87(v2322);
  return v2331;
}

struct StateT * slot_129(struct StateT * v3706) {
  int v3707 = v3706->timer;
  int v3717 = v3707 + 1;
  v3706->timer = v3717;
  int * v3709 = v3706->regs;
  int v3710 = v3709[19];
  int * v3711 = v3706->regs;
  int v3712 = v3711[17];
  int * v3713 = v3706->regs;
  int v3723 = v3710 ^ v3712;
  v3713[19] = v3723;
  struct StateT * v3715 = slot_130(v3706);
  return v3715;
}

struct StateT * slot_158(struct StateT * v4263) {
  int v4264 = v4263->timer;
  int v4272 = v4264 + 1;
  v4263->timer = v4272;
  int * v4266 = v4263->regs;
  int v4267 = v4266[15];
  int * v4268 = v4263->regs;
  int v4277 = (int)((unsigned int)v4267 >> 23);
  v4268[9] = v4277;
  struct StateT * v4270 = slot_159(v4263);
  return v4270;
}

struct StateT * slot_100(struct StateT * v2886) {
  int v2887 = v2886->timer;
  int v2897 = v2887 + 1;
  v2886->timer = v2897;
  int * v2889 = v2886->regs;
  int v2890 = v2889[8];
  int * v2891 = v2886->regs;
  int v2892 = v2891[20];
  int * v2893 = v2886->regs;
  int v2903 = v2890 | v2892;
  v2893[8] = v2903;
  struct StateT * v2895 = slot_101(v2886);
  return v2895;
}

struct StateT * slot_271(struct StateT * v3222) {
  int v3223 = v3222->timer;
  int v3233 = v3223 + 1;
  v3222->timer = v3233;
  int * v3225 = v3222->regs;
  int v3226 = v3225[2];
  int * v3227 = v3222->mem;
  int v3237 = (int)((unsigned int)(v3226 + 56) >> 2);
  int v3228 = v3227[v3237];
  int * v3229 = v3222->regs;
  v3229[24] = v3228;
  struct StateT * v3231 = slot_272(v3222);
  return v3231;
}

struct StateT * slot_127(struct StateT * v3665) {
  int v3666 = v3665->timer;
  int v3676 = v3666 + 1;
  v3665->timer = v3676;
  int * v3668 = v3665->regs;
  int v3669 = v3668[21];
  int * v3670 = v3665->regs;
  int v3671 = v3670[15];
  int * v3672 = v3665->regs;
  int v3682 = v3669 ^ v3671;
  v3672[21] = v3682;
  struct StateT * v3674 = slot_128(v3665);
  return v3674;
}

struct StateT * slot_217(struct StateT * v1139) {
  int v1140 = v1139->timer;
  int v1150 = v1140 + 1;
  v1139->timer = v1150;
  int * v1142 = v1139->regs;
  int v1143 = v1142[2];
  int * v1144 = v1139->mem;
  int v1154 = (int)((unsigned int)(v1143 + 8) >> 2);
  int v1145 = v1144[v1154];
  int * v1146 = v1139->regs;
  v1146[6] = v1145;
  struct StateT * v1148 = slot_218(v1139);
  return v1148;
}

struct StateT * slot_13(struct StateT * v270) {
  int v271 = v270->timer;
  int v281 = v271 + 1;
  v270->timer = v281;
  int * v273 = v270->regs;
  int v274 = v273[2];
  int * v275 = v270->regs;
  int v276 = v275[27];
  int * v277 = v270->mem;
  int v287 = (int)((unsigned int)(v274 + 44) >> 2);
  v277[v287] = v276;
  struct StateT * v279 = slot_14(v270);
  return v279;
}

struct StateT * slot_111(struct StateT * v3327) {
  int v3328 = v3327->timer;
  int v3338 = v3328 + 1;
  v3327->timer = v3338;
  int * v3330 = v3327->regs;
  int v3331 = v3330[9];
  int * v3332 = v3327->regs;
  int v3333 = v3332[26];
  int * v3334 = v3327->regs;
  int v3345 = v3331 + v3333;
  v3334[15] = v3345;
  struct StateT * v3336 = slot_112(v3327);
  return v3336;
}

struct StateT * slot_109(struct StateT * v3243) {
  int v3244 = v3243->timer;
  int v3254 = v3244 + 1;
  v3243->timer = v3254;
  int * v3246 = v3243->regs;
  int v3247 = v3246[5];
  int * v3248 = v3243->regs;
  int v3249 = v3248[20];
  int * v3250 = v3243->regs;
  int v3261 = v3247 ^ v3249;
  v3250[18] = v3261;
  struct StateT * v3252 = slot_110(v3243);
  return v3252;
}

struct StateT * slot_174(struct StateT * v4565) {
  int v4566 = v4565->timer;
  int v4576 = v4566 + 1;
  v4565->timer = v4576;
  int * v4568 = v4565->regs;
  int v4569 = v4568[24];
  int * v4570 = v4565->regs;
  int v4571 = v4570[16];
  int * v4572 = v4565->regs;
  int v4583 = v4569 + v4571;
  v4572[8] = v4583;
  struct StateT * v4574 = slot_175(v4565);
  return v4574;
}

struct StateT * slot_147(struct StateT * v4043) {
  int v4044 = v4043->timer;
  int v4054 = v4044 + 1;
  v4043->timer = v4054;
  int * v4046 = v4043->regs;
  int v4047 = v4046[23];
  int * v4048 = v4043->regs;
  int v4049 = v4048[15];
  int * v4050 = v4043->regs;
  int v4060 = v4047 ^ v4049;
  v4050[23] = v4060;
  struct StateT * v4052 = slot_148(v4043);
  return v4052;
}

struct StateT * slot_42(struct StateT * v814) {
  int v815 = v814->timer;
  int v825 = v815 + 1;
  v814->timer = v825;
  int * v817 = v814->regs;
  int v818 = v817[2];
  int * v819 = v814->regs;
  int v820 = v819[17];
  int * v821 = v814->mem;
  int v831 = (int)((unsigned int)(v818 + 28) >> 2);
  v821[v831] = v820;
  struct StateT * v823 = slot_43(v814);
  return v823;
}

struct StateT * slot_224(struct StateT * v1398) {
  int v1399 = v1398->timer;
  int v1409 = v1399 + 1;
  v1398->timer = v1409;
  int * v1401 = v1398->regs;
  int v1402 = v1401[2];
  int * v1403 = v1398->mem;
  int v1413 = (int)((unsigned int)(v1402 + 20) >> 2);
  int v1404 = v1403[v1413];
  int * v1405 = v1398->regs;
  v1405[7] = v1404;
  struct StateT * v1407 = slot_225(v1398);
  return v1407;
}

struct StateT * slot_163(struct StateT * v4349) {
  int v4350 = v4349->timer;
  int v4360 = v4350 + 1;
  v4349->timer = v4360;
  int * v4352 = v4349->regs;
  int v4353 = v4352[6];
  int * v4354 = v4349->regs;
  int v4355 = v4354[9];
  int * v4356 = v4349->regs;
  int v4366 = v4353 | v4355;
  v4356[6] = v4366;
  struct StateT * v4358 = slot_164(v4349);
  return v4358;
}

struct StateT * slot_184(struct StateT * v4745) {
  int v4746 = v4745->timer;
  int v4754 = v4746 + 1;
  v4745->timer = v4754;
  int * v4748 = v4745->regs;
  int v4749 = v4748[8];
  int * v4750 = v4745->regs;
  int v4759 = (int)((unsigned int)v4749 >> 19);
  v4750[9] = v4759;
  struct StateT * v4752 = slot_185(v4745);
  return v4752;
}

struct StateT * slot_204(struct StateT * v5121) {
  int v5122 = v5121->timer;
  int v5130 = v5122 + 1;
  v5121->timer = v5130;
  int * v5124 = v5121->regs;
  int v5125 = v5124[8];
  int * v5126 = v5121->regs;
  int v5135 = (int)((unsigned int)v5125 >> 14);
  v5126[9] = v5135;
  struct StateT * v5128 = slot_205(v5121);
  return v5128;
}

struct StateT * slot_194(struct StateT * v4941) {
  int v4942 = v4941->timer;
  int v4952 = v4942 + 1;
  v4941->timer = v4952;
  int * v4944 = v4941->regs;
  int v4945 = v4944[1];
  int * v4946 = v4941->regs;
  int v4947 = v4946[24];
  int * v4948 = v4941->regs;
  int v4959 = v4945 + v4947;
  v4948[8] = v4959;
  struct StateT * v4950 = slot_195(v4941);
  return v4950;
}

struct StateT * slot_165(struct StateT * v4386) {
  int v4387 = v4386->timer;
  int v4395 = v4387 + 1;
  v4386->timer = v4395;
  int * v4389 = v4386->regs;
  int v4390 = v4389[8];
  int * v4391 = v4386->regs;
  int v4399 = v4390 << 9;
  v4391[8] = v4399;
  struct StateT * v4393 = slot_166(v4386);
  return v4393;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v2383) {
  int v2384 = v2383->timer;
  int v2394 = v2384 + 1;
  v2383->timer = v2394;
  int * v2386 = v2383->regs;
  int v2387 = v2386[10];
  int * v2388 = v2383->regs;
  int v2389 = v2388[12];
  int * v2390 = v2383->mem;
  int v2400 = (int)((unsigned int)(v2387 + 16) >> 2);
  v2390[v2400] = v2389;
  struct StateT * v2392 = slot_251(v2383);
  return v2392;
}

struct StateT * slot_259(struct StateT * v2749) {
  int v2750 = v2749->timer;
  int v2760 = v2750 + 1;
  v2749->timer = v2760;
  int * v2752 = v2749->regs;
  int v2753 = v2752[10];
  int * v2754 = v2749->regs;
  int v2755 = v2754[24];
  int * v2756 = v2749->mem;
  int v2766 = (int)((unsigned int)(v2753 + 52) >> 2);
  v2756[v2766] = v2755;
  struct StateT * v2758 = slot_260(v2749);
  return v2758;
}

struct StateT * slot_117(struct StateT * v3486) {
  int v3487 = v3486->timer;
  int v3497 = v3487 + 1;
  v3486->timer = v3497;
  int * v3489 = v3486->regs;
  int v3490 = v3489[15];
  int * v3491 = v3486->regs;
  int v3492 = v3491[6];
  int * v3493 = v3486->regs;
  int v3503 = v3490 | v3492;
  v3493[15] = v3503;
  struct StateT * v3495 = slot_118(v3486);
  return v3495;
}

struct StateT * slot_249(struct StateT * v2342) {
  int v2343 = v2342->timer;
  int v2353 = v2343 + 1;
  v2342->timer = v2353;
  int * v2345 = v2342->regs;
  int v2346 = v2345[10];
  int * v2347 = v2342->regs;
  int v2348 = v2347[14];
  int * v2349 = v2342->mem;
  int v2359 = (int)((unsigned int)(v2346 + 12) >> 2);
  v2349[v2359] = v2348;
  struct StateT * v2351 = slot_250(v2342);
  return v2351;
}

struct StateT * slot_90(struct StateT * v2486) {
  int v2487 = v2486->timer;
  int v2497 = v2487 + 1;
  v2486->timer = v2497;
  int * v2489 = v2486->regs;
  int v2490 = v2489[25];
  int * v2491 = v2486->regs;
  int v2492 = v2491[18];
  int * v2493 = v2486->regs;
  int v2503 = v2490 ^ v2492;
  v2493[25] = v2503;
  struct StateT * v2495 = slot_91(v2486);
  return v2495;
}

struct StateT * slot_11(struct StateT * v228) {
  int v229 = v228->timer;
  int v239 = v229 + 1;
  v228->timer = v239;
  int * v231 = v228->regs;
  int v232 = v231[2];
  int * v233 = v228->regs;
  int v234 = v233[25];
  int * v235 = v228->mem;
  int v245 = (int)((unsigned int)(v232 + 52) >> 2);
  v235[v245] = v234;
  struct StateT * v237 = slot_12(v228);
  return v237;
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
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[20 + i] = bounded(0, 20);
    s2.mem[20 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}